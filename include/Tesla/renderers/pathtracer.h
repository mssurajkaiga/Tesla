#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <Tesla/renderers/renderer.h>
#include <Tesla/core/sampler.h>

class PathTracer : public Renderer
{
public:
	Sampler* sampler;
	int depth;
	PathTracer();
	PathTracer(Sampler* sampler, int depth);
	void render(Scene* scene);
};

#endif