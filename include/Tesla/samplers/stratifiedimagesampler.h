#ifndef STRATIFIEDIMAGESAMPLER_H
#define STRATIFIEDIMAGESAMPLER_H

#include <Tesla/samplers/imagesampler.h>
#include <Tesla/core/randomizer.h>

class StratifiedImageSampler : public ImageSampler
{
protected:
	bool jitter;
	int xcurr, ycurr, sppcurr, X, Y;
	Randomizer* rng;

public:
	StratifiedImageSampler(int xmin = 0, int xmax = 800, int ymin = 0, int ymax = 600, int spp = 1, bool j = true);
	ImageSample* getSample();
	inline void setRandomizer(Randomizer* r) { rng = r; }
	void generateAllSamples();
	void generateSubSamples(int x, int y);
};

#endif