#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <Tesla/renderers/renderer.h>
#include <Tesla/samplers/imagesampler.h>
#include <Tesla/integrators/integrator.h>

class PathTracer : public Renderer
{
protected:
	ImageSampler *imagesampler;
	Integrator *integrator;
public:
	PathTracer(ImageSampler *sampler = NULL, Integrator *i = NULL, Film* f = NULL);
	void render(Scene* scene, Camera *camera);
	bool getIntersection(Scene *scene, Ray r, Intersection* intersection);
};

#endif