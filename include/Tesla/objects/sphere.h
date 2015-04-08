#ifndef SPHERE_H
#define SPHERE_H

#include <Tesla/objects/object.h>
#include <Tesla/core/ray.h>

class Sphere: public Object {
private:
	Point center;
	Real radius;

public:
	Sphere(Point c = Point(0., 0., 0.), Real r = 1.0, Material *mat = NULL);
	bool intersects(const Ray &r, Intersection* i = NULL) const;
	void setBBox();
	Vector3f sample() const;
};

#endif