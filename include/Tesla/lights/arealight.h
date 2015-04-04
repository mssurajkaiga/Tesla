#ifndef AREALIGHT_H
#define AREALIGHT_H

#include <Tesla/lights/light.h>

/* 
Represents a general area light.
AreaLight should return the spectral intesity at a point on it.
The spectral intensity of light can vary with position on the light.
*/
class AreaLight : public Light {
public:
	AreaLight() : Light() {}
	virtual Spectrum getIntensity(Point &p) const = 0;
};

#endif