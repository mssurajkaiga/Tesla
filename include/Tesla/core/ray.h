#ifndef RAY_H
#define RAY_H

#include <Tesla/core/core.h>

/* A ray */
struct Ray
{
	Point origin;
	Vector3f direction;
	float t_min, t_max;
	Ray()
	{
		origin = Point(0,0,0);
		direction = Vector3f(0,0,0);
		t_min = 0;
		t_max = INFINITY;
	}
	/* ray(t) = origin + t*direction, where t_min <= t <= t_max */
};

#endif