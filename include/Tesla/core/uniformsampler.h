#ifndef UNIFORMSAMPLER_H
#define UNIFORMSAMPLER_H

#include <Tesla/core/sampler.h>

class UniformSampler : public Sampler
{
public:
	UniformSampler(); // initialize with default values
	UniformSampler(int xmin, int xmax, int ymin, int ymax, int spp);
	Sample getSample();
};

#endif