#include <Tesla/lights/quadlightsource.h>
#include <Tesla/objects/quad.h>

Spectrum QuadLightSource::getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const {
	
	return Spectrum(0., 0., 0.);
}

Spectrum QuadLightSource::getIntensity(const Point &point) const {
	return spectrum * intensity;
}