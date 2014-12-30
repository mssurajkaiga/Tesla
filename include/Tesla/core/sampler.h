#ifndef SAMPLER_H
#define SAMPLER_H

#include <Tesla/core/core.h>
#include <Tesla/core/sample.h>

class Sampler
{
public:
	virtual Sample getSample() = 0;
};

#endif