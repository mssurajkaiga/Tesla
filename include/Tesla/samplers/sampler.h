#ifndef SAMPLER_H
#define SAMPLER_H

#include <Tesla/core/core.h>
#include <Tesla/samplers/sample.h>

class Sampler {
public:
	virtual std::unique_ptr<Sample> getSample() const { return NULL; }
};

#endif