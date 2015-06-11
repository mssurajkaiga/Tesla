#include <Tesla/samplers/stratifiedimagesampler.h>

StratifiedImageSampler::StratifiedImageSampler(int xmin, int xmax, int ymin, int ymax, int spp, bool j) : ImageSampler(xmin, xmax, ymin, ymax, spp), jitter(j), xcurr(0), ycurr(0), sppcurr(0) {
	X = xmax - xmin;
	Y = ymax - ymin;
	rng = &ung;
}

std::unique_ptr<ImageSample> StratifiedImageSampler::getSample() {	
	if (sppcurr == spp) {
		sppcurr = 0;
		++xcurr;
	}
	if (xcurr == X) {
		xcurr = 0;
		++ycurr;
	}
	if (ycurr == Y) {
		// no more samples
		return NULL;
	}
	++sppcurr;

	if (jitter) {
		return std::unique_ptr<ImageSample>(new ImageSample(xmin + xcurr + rng->generateRandom(), ymin + ycurr + rng->generateRandom()));
	}
	else {
		return std::unique_ptr<ImageSample>(new ImageSample(xmin + xcurr + 0.5, ymin + ycurr + 0.5));
	}
}