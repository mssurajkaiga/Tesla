#ifndef SAMPLER_H
#define SAMPLER_H

#include <Tesla/core/core.h>
#include <Tesla/core/sample.h>

class Sampler
{
public:
	int xmin, xmax, ymin, ymax, spp; // x,y pixel limits and samples-per-pixel
	virtual Sample getSample() = 0;
};

#endif