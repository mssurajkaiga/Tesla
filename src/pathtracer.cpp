#include <Tesla/renderers/pathtracer.h>
#include <Tesla/samplers/uniformimagesampler.h>
#include <Tesla/integrators/ptintegrator.h>
#include <iostream>

PathTracer::PathTracer(ImageSampler *sampler, Integrator *i, Film* f) : Renderer(f), imagesampler(sampler), integrator(i) {
	if (!integrator) {
		integrator = new PTIntegrator(1, 10, RUSSIAN_ROULETTE, GLOBAL);
	}
	if (!sampler) {
		sampler = new UniformImageSampler;
	}
}

void PathTracer::render(Scene *scene, Camera *camera) {
	/* add preprocess calls like building acceleration structures, setting timer, etc here and then render */

	/* render and store in film */
	std::vector<Spectrum> values;
	Spectrum radiance(0., 0., 0.);
	Intersection i;
	Ray r;
	ImageSample* is;
	int spp = imagesampler->spp, count = 0;
	while (is = imagesampler->getSample()) {
		r = camera->generateRay(imagesampler, is);
		radiance += integrator->getRadiance(&r, &i, scene, this, is);
		if (++count == spp) {
			count = 0;
			values.push_back(radiance/spp);
			radiance = Spectrum(0., 0., 0.);
		}
	}

	film->store(values);
}

bool PathTracer::getIntersection(Scene *scene, Ray r, Intersection* intersection) {
	return false;
}