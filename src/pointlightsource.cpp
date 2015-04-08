#include <Tesla/lights/pointlightsource.h>

PointLightSource::PointLightSource(Spectrum s, Real i) : LightSource(), spectrum(s), intensity(i) {
	position = Vector3f(INFINITY, INFINITY, INFINITY);
}

PointLightSource::PointLightSource(const Vector3f position, const Spectrum spectrum, Real intensity) : LightSource () {
	this->position = position;
	this->spectrum = spectrum;
	this->intensity = intensity;
}

Spectrum PointLightSource::getSample(const Vector3f &point, Point &sample, Real &pdf) const {
	sample = position;
	pdf = (position-point).squaredNorm();
	return spectrum * intensity;
}

Spectrum PointLightSource::getIntensity(const Point &point) const {
	return spectrum * intensity;
}