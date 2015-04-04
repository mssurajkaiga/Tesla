#ifndef IMAGESAMPLE_H
#define IMAGESAMPLE_H

#include <Tesla/samplers/sample.h>

class ImageSample : public Sample
{
public:
	Real x, y;
	// Additional properties for future use
	ImageSample(Real x = 0., Real y = 0.) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream &os, ImageSample &is) {
		return os << "ImageSample(" << is.x << ", " << is.y << ")";
	}
};

#endif