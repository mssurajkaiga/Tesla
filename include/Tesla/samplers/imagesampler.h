#ifndef IMAGESAMPLER_H
#define IMAGESAMPLER_H

#include <Tesla/core/core.h>
#include <Tesla/samplers/sampler.h>
#include <Tesla/samplers/imagesample.h>
#include <vector>

class ImageSampler : public Sampler
{
protected:
	std::vector<std::vector<ImageSample>> imagesamples;
public:
	int xmin, xmax, ymin, ymax, spp; // x,y pixel range and samples-per-pixel for sample generation
	ImageSampler(int xmin, int xmax, int ymin, int ymax, int s) : xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax), spp(s) {}
	virtual std::unique_ptr<ImageSample> getSample() = 0;
};

#endif