#ifndef RAY_H
#define RAY_H

#include <Tesla/core/core.h>

/* A ray */
struct Ray
{
	Point origin;
	Vector3f direction;
	Real t_min, t_max;

	Ray(Point ori = Point(0, 0, 0), Vector3f dir = Vector3f(0, 0, 0), Real mi = 0, Real ma = INFINITY)
	{
		origin = ori;
		direction = dir;
		t_min = mi;
		t_max = ma;
	}
	/* ray(t) = origin + t*direction, where t_min <= t <= t_max */

	void shift(Vector3f* dir = NULL) {
		if (dir) {
			origin = origin + (*dir) * SHIFT_EPSILON;
		}
		else {
			origin = origin + direction * SHIFT_EPSILON;
		}
	}
};

#endif