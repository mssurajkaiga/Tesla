#include <Tesla/lights/pointlight.h>

PointLight::PointLight() {
	position = Vector3f(INFINITY, INFINITY, INFINITY);
	color = Color(0., 0., 0.);
	intensity = 1.0;
}

PointLight::PointLight(const Vector3f &pos, const Vector3f &col, double inten) {
	position = pos;
	color = color;
	intensity = inten;
}

Color PointLight::getSample(const Vector3f point, Vector3f *wi) {
	*wi = position - point;
	(*wi).normalize();
	return color * intensity;
}