#ifndef UNIFORMIMAGESAMPLER_H
#define UNIFORMIMAGESAMPLER_H

#include <Tesla/samplers/stratifiedimagesampler.h>

class UniformImageSampler : public StratifiedImageSampler
{
private:
	ImageSample *imagesamples;
public:
	UniformImageSampler(int xmin = 0, int xmax = 800, int ymin = 0, int ymax = 600, int spp = 1) : StratifiedImageSampler(xmin, xmax, ymin, ymax, spp, false) {}
};

#endif