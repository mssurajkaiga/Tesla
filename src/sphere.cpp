#include <Tesla/objects/sphere.h>
#include <utility>

Sphere::Sphere(Point c, Real r, Material *mat) : Object(mat), center(c), radius(r) {
	setBBox();
}

bool Sphere::intersects(const Ray &r, Intersection* i) const {
	/*
	if (!bbox.intersects(r)) {
		return false;
	}
	*/

	Real A,B,C,D, t_hit = INFINITY;
	A = r.direction.squaredNorm();
	B = r.direction.dot(2 * (r.origin - center));
	Vector3f t = r.origin - center;
	C = t.dot(t) - radius*radius;

	D = B * B - 4.f * A * C; /* discriminant for calculating if intersection occurs or not */

	if (D<0) {
		return false;
	}

	else if (D==0) {
		t_hit = -0.5 * B / A;
	}

	else {
		Real q;
		if (B < 0.) 
			q = -0.5 * (B - sqrtf(D));
		else
			q = -0.5 * (B + sqrtf(D));

		Real t1 = q / A;
		Real t2 = C / q;

		if (t1 > t2) {
			std::swap(t1, t2);
		}

		if (t1 > r.t_max || t2 < r.t_min) {
			return false;
		}

		t_hit = t1;
		if (t1 < r.t_min) {
			t_hit = t2;
			if (t2 > r.t_max) {
				t_hit = INFINITY;
				return false;
			}
		}

		if (i) {
			i->t = t_hit;
			i->point = r.origin + t_hit * r.direction;
			i->normal = i->point - center;
			i->normal.normalize();
			i->object = (Object*)this;
		}

		return true;

	}
}

void Sphere::setBBox() {
	this->bbox = BBox(center-Point(radius, radius, radius), center+Point(radius, radius, radius));
}

/* to do */
Vector3f Sphere::sample() const {
	return Vector3f(0.0, 0.0, 0.0);
}