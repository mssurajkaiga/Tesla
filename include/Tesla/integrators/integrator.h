#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <Tesla/samplers/imagesampler.h>
#include <Tesla/samplers/imagesample.h>
#include <Tesla/core/scene.h>
#include <Tesla/renderers/renderer.h>

enum TerminationCriterion {
	RUSSIAN_ROULETTE, MAX_DEPTH
};

enum Illumination {
	DIRECT, INDIRECT, GLOBAL
};

class Integrator
{
public:
	virtual void getSamples(ImageSampler *sampler, ImageSample *samples, Scene *scene) const {};
	virtual Spectrum getRadiance(Ray *ray, Intersection *isect, Scene *scene, Renderer *renderer, ImageSample *imagesample) const { return Spectrum(0., 0., 0.); };
};

#endif