#include <Tesla/integrators/ptintegrator.h>
#include <Tesla/core/randomizer.h>
#include <Tesla/bsdfs/bsdf.h>
#include <iostream>

PTIntegrator::PTIntegrator(int min_depth, int max_depth, TerminationCriterion tc, Illumination i) {
	this->tc = tc;
	this->min_depth = min_depth;
	this->max_depth = max_depth;
	this->illumination = i;
}

Spectrum PTIntegrator::getRadiance(Ray *ray, Intersection *isect, Scene *scene, Renderer *renderer, ImageSample *imagesample) const {
	Spectrum radiance(0., 0., 0.);
	Path path = generatePath(ray, scene);
	path.reset_iterator();
	//std::cout << "Path = " << path << "\n";
	Edge *edge1, *edge2;

	if (!(edge1 = path.get_edge_backward())) { // path is only a point
		return radiance;
	}

	Spectrum ld(0., 0., 0.), f(0., 0., 0.);
	Real lpdf = 1.;
	Object *l = NULL;
	Point samplelocation;
	Vector3f direction;
	Real pdf = 1.;
	bool islight = false;
	/* check if terminal vertex is a light. If so, no need to calculate direct lighting from other lights here and
	 at the next vertex, this light source should not be shadow connected. use islight flag and comparison at next vertex. 
	 Update: currently, this vertex may be shadow connected at next vertex */
	if (islight = edge1->begin->object->isLight()) {
		ld = edge1->begin->object->getLightSource()->getIntensity(edge1->begin->position);
	}

	/* else calculate the direct lighting at non-light terminal vertex */
	else if ((illumination != INDIRECT) && (l = scene->getLight(lpdf))) {
		Spectrum s = l->getSample(edge1->begin->position, samplelocation, pdf);
		direction = samplelocation - edge1->begin->position;
		if (!scene->intersects(Ray(edge1->begin->position, direction))){ //shadow ray intersection
			ld += s / (pdf * lpdf);
			f = edge1->begin->object->getMaterial()->eval(edge1->direction, direction); //check directions
			ld *= f;
		}
	}

	radiance = ld; // terminal vertex has only direct lighting

	while(edge2 = path.get_edge_backward()) {
		/* calculate direct lighting contribution */
		ld = Spectrum(0., 0., 0.);
		Object *lo;
		if ((lo = scene->getLight(lpdf)) && (illumination != INDIRECT)){
			Spectrum s = lo->getSample(edge1->begin->position, samplelocation, pdf);
			direction = samplelocation - edge1->begin->position;
			if (!scene->intersects(Ray(edge2->begin->position, direction))) { //shadow ray intersection
				ld += s / (pdf * lpdf);
				f = edge1->end->object->getMaterial()->eval(edge2->direction, direction); //check directions
				ld *= f;
			}
		}
		/* calculate indirect lighting contribution */
		if (illumination != DIRECT) {
			f = edge1->end->object->getMaterial()->eval(edge2->direction, edge1->direction); //todo = -ve the directions as we are tracing backward
			radiance = ld + f * radiance * edge2->direction.dot(edge1->end->normal) / (edge1->end->pdf * edge1->end->apdf);
		}
		else {
			radiance = ld;
		}

		edge1 = edge2;
		islight = false;
	}

	//todo - check if additional radiance is added at eye vertex
	return radiance/path.length();
}

Path PTIntegrator::generatePath(Ray* ray, Scene* scene) const {
	// get ray-scene intersection
	Path path;
	path.add_vertex(PathVertex(ray->origin));

	Ray r = *ray;
	Material *mat;
	Real apdf = 1., sp = 0.75; //russian roulette survival probability
	int bounces = 1;

	while (1) {
		bool terminate = false;

		Real random;
		/* termination based on criterion */
		switch (this->tc) {
			case RUSSIAN_ROULETTE:
				if (bounces > min_depth) {
					random = ung.generateRandom();
					if (random > sp){
						terminate = true;
						apdf = sp;
					}
				}
				break;

			case MAX_DEPTH:
				if (bounces == max_depth)
					terminate = true;
				break;
		}

		Intersection is;
		if (!scene->intersects(r, &is)) {
			return path;
		}

		/* If intersection is light or termination check succeeds, path should be terminated */
		if (is.object->isLight() || terminate) {
			path.add_vertex(PathVertex(&is));
			break;
		}

		/* Importance sampling brdf to get new direction */
		mat = is.getMaterial(); //get BSDF at intersection location
		Vector3f wi; // sampled incoming direction
		Real pdf; // sampled pdf value

		mat->sample(r.direction, wi, is.normal, pdf);
		path.add_vertex(PathVertex(&is, pdf, apdf));

		/* update new ray in sampled direction */
		r.direction = wi;
		r.origin = is.point;
		r.shift();

		++bounces;
	}

	return path;
}