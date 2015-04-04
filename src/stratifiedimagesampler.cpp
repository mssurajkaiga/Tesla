#include <Tesla/samplers/stratifiedimagesampler.h>

StratifiedImageSampler::StratifiedImageSampler(int xmin, int xmax, int ymin, int ymax, int spp, bool j) : ImageSampler(xmin, xmax, ymin, ymax, spp), jitter(j), xcurr(0), ycurr(0), sppcurr(0) {
	//generate set of stratified samples and store it
	X = xmax - xmin;
	Y = ymax - ymin;
	imagesamples.resize(X);
	for (int i = 0; i < X; ++i) {
		imagesamples[i].resize(Y);
		for (int j = 0; j < Y; ++j)
			imagesamples[i][j].resize(spp);
	}
	rng = &ung;
	generateAllSamples();
}

void StratifiedImageSampler::generateAllSamples() {
	for (int y = 0; y < Y; ++y) {
		for (int x = 0; x < X; ++x) {
			generateSubSamples(x, y);
		}
	}
}

void StratifiedImageSampler::generateSubSamples(int x, int y) {
	for (int i = 0; i < spp; ++i) {
		if (jitter) {
			imagesamples[x][y][i] = ImageSample(xmin + x + rng->generateRandom(), ymin + y + rng->generateRandom());
		}
		else {
			imagesamples[x][y][i] = ImageSample(xmin + x + 0.5, ymin + y + 0.5);
		}
	}
}
ImageSample* StratifiedImageSampler::getSample() {	
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
	ImageSample* is = &imagesamples[xcurr][ycurr][sppcurr++];
	return is;
}