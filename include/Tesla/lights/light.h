#ifndef LIGHT_H
#define LIGHT_H

#include <Tesla/core/color.h>

class Light
{
public:
	int nSamples;
	/* Change it to support spectrum class */
	virtual Color getSample(const Vector3f point, Vector3f *wi) = 0;
};

#endif