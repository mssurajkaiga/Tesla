#include <Tesla/core/uniformsampler.h>

UniformSampler::UniformSampler() {
	this->xmin = 0;
	this->xmax = 800;
	this->ymin = 0;
	this->ymax = 600;
	this->spp = 1;
}

UniformSampler::UniformSampler(int xmin, int xmax, int ymin, int ymax, int spp) {
	this->xmin = xmin;
	this->xmax = xmax;
	this->ymin = ymin;
	this->ymax = ymax;
	this->spp = spp;
}

Sample UniformSampler::getSample() {
	return *(new Sample); // to do implement sample generator
}