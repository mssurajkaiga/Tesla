#ifndef DIRECTIONSAMPLER_H
#define DIRECTIONSAMPLER_H

#include <Tesla/samplers/sampler.h>

class DirectionSampler : public Sampler {
public:
	virtual void getDirectionSample(Vector3f &direction, Real &pdf) const = 0;
};

#endif