#ifndef CORE_H
#define CORE_H

#include <Tesla/core/spectrum.h>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

#define PI 3.14159265359
#define PI_INV 0.31830988618
#define MIN_VAL 0.0000001
#define CRS 3 /* Color representation samples */

/* change them together */
#define SHIFT_EPSILON 1e-5; //FLT_MIN is too small
typedef float Real;

typedef Vector3f Point;

inline std::ostream& operator<<(std::ostream &os, Vector3f &a) {
	return os << "Vector3f(" << a(0) << ", " << a(1) << ", " << a(2) <<")";
}

#endif