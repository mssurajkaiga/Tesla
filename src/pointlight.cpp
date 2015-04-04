#include <Tesla/lights/pointlight.h>

PointLight::PointLight() : Light() {
	position = Vector3f(INFINITY, INFINITY, INFINITY);
	spectrum = Spectrum(0., 0., 0.);
	intensity = 1.0;
}

PointLight::PointLight(const Vector3f position, const Spectrum spectrum, Real intensity) : Light () {
	this->position = position;
	this->spectrum = spectrum;
	this->intensity = intensity;
}

Spectrum PointLight::getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const {
	wi = position - point;
	pdf = wi.dot(wi);
	wi.normalize();
	return spectrum * intensity;
}

Spectrum PointLight::getIntensity(const Point &point) const {
	return Spectrum(0., 0., 0.); 
}