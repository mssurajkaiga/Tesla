#include <Tesla/renderers/pathtracer.h>
#include <Tesla/samplers/uniformimagesampler.h>
#include <Tesla/integrators/ptintegrator.h>
#include <iostream>


void PathTracer::render(Scene *scene, Camera *camera) {
	/* add preprocess calls like building acceleration structures, setting timer, etc here and then render */

	/* render and store in film */
	std::vector<Spectrum> values;
	Spectrum radiance(0., 0., 0.);
	Intersection it;
	Ray r;
	std::unique_ptr<ImageSample> is;

	std::cout << "Rendering progress - \n0%";
	int length = (imagesampler->xmax - imagesampler->xmin) * (imagesampler->ymax - imagesampler->ymin) * imagesampler->spp / 100;
	int i = 0, percentage = 0;
	int spp = imagesampler->spp, count = 0;
	while (is = imagesampler->getSample()) {
		++i;
		r = camera->generateRay(imagesampler, is.get());
		radiance += integrator->getRadiance(&r, &it, scene, this, is.get());
		if (++count == spp) {
			count = 0;
			values.push_back(radiance/spp);
			radiance = Spectrum(0., 0., 0.);
		}
		if (i%length==0){
			++percentage;
			std::cout << "\r" << percentage << "% " << std::flush;
		}
	}

	film->store(values);
}

bool PathTracer::getIntersection(Scene *scene, Ray r, Intersection* intersection) {
	return false;
}