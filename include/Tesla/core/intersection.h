#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <Tesla/core/core.h>

class Object;

/* Represents an intersection
	stores the parametric value, point, normal
	and a reference to the object of interesection */
struct Intersection
{
	double t;
	Vector3f point, normal;
	Object* object;
};

#endif