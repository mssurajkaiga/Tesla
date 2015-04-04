#include <Tesla/integrators/ptintegrator.h>
#include <Tesla/core/randomizer.h>
#include <Tesla/bsdfs/bsdf.h>
#include <iostream>

PTIntegrator::PTIntegrator(TerminationCriterion tc = MAX_DEPTH, int md = 5) {
	this->tc = tc;
	this->max_depth = md;
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
	Light *l;
	Vector3f direction;
	Real pdf = 1.;
	/* check if terminal vertex is a light. If so, no need to calculate direct lighting from other lights here */
	if (edge1->begin->object->isLight()) {
		l = (Light*)edge1->begin->object;
		ld = l->getIntensity(edge1->begin->position);
	}

	/* else calculate the direct lighting at non-light terminal vertex */
	else {
		l = scene->getLight(lpdf);
		Spectrum s = l->getSample(edge1->begin->position, direction, pdf);
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
		Real lpdf = 1.;
		Light *l = scene->getLight(lpdf);
		Spectrum s = l->getSample(edge2->begin->position, direction, pdf);
		if (!scene->intersects(Ray(edge2->begin->position, direction))) { //shadow ray intersection
			ld += s / (pdf * lpdf);
			f = edge1->end->object->getMaterial()->eval(edge2->direction, direction); //check directions
			ld *= f;
		}

		/* calculate indirect lighting contribution */
		f = edge1->end->object->getMaterial()->eval(edge2->direction, edge1->direction); //todo = -ve the directions as we are tracing backward
		radiance = ld + f * radiance * edge2->direction.dot(edge1->end->normal) / (edge1->end->pdf * edge1->end->apdf);
		edge1 = edge2;
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
	Real sp = 0.5; //russian roulette survival probability
	int bounces = 1;

	while (1) {
		bool terminate = false;

		Intersection is;
		if (!scene->intersects(r, &is)) {
			return path;
		}

		
		/* If intersection is light, path should be terminated */
		if (is.object->isLight()) {
			path.add_vertex(PathVertex(&is));
			return path;
		}

		/* Importance sampling brdf to get new direction */
		mat = is.getMaterial(); //get BSDF at intersection location
		Vector3f wi; // sampled incoming direction
		Real pdf; // sampled pdf value

		mat->sample(r.direction, wi, is.normal, pdf);
		path.add_vertex(PathVertex(&is, pdf));

		Real random;
		/* termination based on criterion */
		switch (this->tc) {
			case RUSSIAN_ROULETTE:
				random = ung.generateRandom();
				if (random > sp)
					terminate = true;
				break;

			case MAX_DEPTH:
				if (bounces == max_depth)
					terminate = true;
				break;

			case BOTH:
				if (bounces == max_depth)
					terminate = true;
				random = ung.generateRandom();
				if (random > sp)
					terminate = true;
		}

		if (terminate)
			break;
		++bounces;

		/* update new ray in sampled direction */
		r.direction = wi;
		r.origin = is.point;
		r.shift();
	}

	return path;
}