#ifndef SPHERE_H
#define SPHERE_H

#include <Tesla/objects/object.h>
#include <Tesla/core/ray.h>

class Sphere: public Object {
private:
	Vector3f center;
	double radius;

public:
	Sphere();
	Sphere(const Vector3f &c, double r);
	bool intersects(Ray &r, Intersection* i);
	void setBBox();
	Vector3f sample() const;
};

#endif