#include <Tesla/objects/sphere.h>

Sphere::Sphere() {
	center = Vector3f(0., 0., 0.);
	radius = 1.0;
	this->setBBox();
}

Sphere::Sphere(const Vector3f &c, double r) {
	center = c;
	radius = r;
	this->setBBox();
}

bool Sphere::intersects(Ray &r, Intersection* i) {
	if (!bbox.intersects(r)) {
		return false;
	}

	double A,B,C,D, t_hit;
	A = r.direction.squaredNorm();
	B = r.direction.dot(2 * (r.origin - center));
	Vector3f t = r.origin - center;
	C = t.squaredNorm() - radius*radius;

	D = B * B - 4 * A * C; /* discriminant for calculating if intersection occurs or not */

	if (D<0) {
		t_hit = INFINITY;
		return false;
	}

	else if (D==0) {
		t_hit = -B/(2*A);
	}

	else {
		double t1 = (-B-sqrt(D))/(2*A);
		double t2 = (-B+sqrt(D))/(2*A);

		if (t1 < r.t_min && t2 >= r.t_min) {
			if (t2 <= r.t_max) {
				t_hit = t2;
			}
			else {
				t_hit = INFINITY;
				return false;
			}
		}

		else if (t1>=r.t_min && t1<=r.t_max) {
			t_hit = t1;
		}

		else {
			t_hit = INFINITY;
			return false;
		}

		if (i) {
			i->t = t_hit;
			i->point = r.origin + t_hit * r.direction;
			/* calculate i.normal */
			i->normal = i->point - center;
			i->normal.normalize();
			i->object = this;
		}

		return true;

	}
}

void Sphere::setBBox() {
	this->bbox = BBox(center-Vector3f(radius, radius, radius), center+Vector3f(radius, radius, radius));
}

/* to do */
Vector3f Sphere::sample() const {
	return Vector3f(0.0, 0.0, 0.0);
}