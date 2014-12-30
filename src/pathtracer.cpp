#include <Tesla/renderers/pathtracer.h>
#include <Tesla/core/uniformsampler.h>

PathTracer::PathTracer() {
	this->sampler = new UniformSampler;
	depth = 5;
}

PathTracer::PathTracer(Sampler *sampler, int depth) {
	this->sampler = sampler;
	this->depth = depth;
}

void PathTracer::render(Scene* scene) {
	return;
}