#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <Tesla/core/core.h>
#include <Tesla/core/ray.h>	
#include <Tesla/bsdfs/bsdf.h>

extern class Object;
extern class Material;

/* Represents an intersection
stores the parametric value, point, normal
and a reference to the object (and light) of interesection */
class Intersection
{
public:
	Real t;
	Vector3f point, normal;
	Object* object = NULL;

	Intersection(Real t = INFINITY, Vector3f point = Vector3f(0., 0., 0. ), Vector3f normal = Vector3f(0., 0., 0.), Object* object = NULL);

	Material* getMaterial();

	void copy(Intersection &in);

	friend std::ostream& operator<<(std::ostream &os, Intersection &i);
};

#endif