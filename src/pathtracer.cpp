#include <Tesla/renderers/pathtracer.h>
#include <Tesla/core/uniformsampler.h>
#include <Tesla/core/spectrum.h>

PathTracer::PathTracer() {
	this->sampler = new UniformSampler;
	depth = 5;
}

PathTracer::PathTracer(Sampler *sampler, int depth) {
	this->sampler = sampler;
	this->depth = depth;
}

void PathTracer::render(Scene *scene) {
	return;
}

/*
Color PathTracer::trace(Scene *scene, Ray r, int depth) {
	if (depth==this->depth) {
		return Color(0.0, 0.0, 0.0);
	}

	Intersection intersection;
	if (!getIntersection(scene, r, &intersection)) {
		return Color(0.0, 0.0, 0.0);
	}

	Ray shadowray, secondaryray;

	secondaryray.origin = Point(intersection.point + MIN_VAL * intersection.normal); // displacement to prevent self-intersection with object
	secondaryray.direction = cosineWeightedHemisphereDirection(intersection.normal); // cosine-weighted hemisphere sampling

	float costheta = secondaryray.direction.dot(intersection.normal);
	intersection.object->getMaterial();

    return Color(0., 0., 0.);
}
*/

bool getIntersection(Scene *scene, Ray r, Intersection* intersection) {
	return false;
}

/*
Vector3f cosineWeightedHemisphereDirection(Vector3f normal) {
    float Xi1 = (float)rand()/(float)RAND_MAX;
    float Xi2 = (float)rand()/(float)RAND_MAX;

    float  theta = acos(sqrt(1.0-Xi1));
    float  phi = 2.0 * pi * Xi2;

    float xs = sinf(theta) * cosf(phi);
    float ys = cosf(theta);
    float zs = sinf(theta) * sinf(phi);

    Vector3f y(normal(0), normal(1), normal(2));
    Vector3f h = y;
    if (fabs(h(0))<=fabs(h(1)) && fabs(h(0))<=fabs(h(2)))
        h(0)= 1.0;
    else if (fabs(h(1))<=fabs(h(0)) && fabs(h(1))<=fabs(h(2)))
        h(1)= 1.0;
    else
        h(2)= 1.0;


    Vector3f x = (h * y).normalize(); //check - replace * with ^
    Vector3f z = (x * y).normalize(); //check - replace * with ^

    Vector3f direction = xs * x + ys * y + zs * z;
    direction.normalize();
    return direction;
}
*/