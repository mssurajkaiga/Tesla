#include <Tesla/core/intersection.h>
#include <Tesla/objects/object.h>
#include <Tesla/materials/material.h>

Intersection::Intersection(Real t, Vector3f p, Vector3f n, Object* o) : t(t), point(p), normal(n), object(o) {
}

Material* Intersection::getMaterial() {
	if (!object->isLight())
		return object->getMaterial(this);
	return NULL;
}

void Intersection::copy(Intersection &in) {
	t = in.t;
	point = in.point;
	normal = in.normal;
	object = in.object;
}

std::ostream& operator<<(std::ostream &os, Intersection &i) {
	return os << "Intersection(" << i.t << ", " << i.point << ", " << i.normal << ", " << *(i.object) << ")";
}