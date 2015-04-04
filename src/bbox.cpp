#include <Tesla/objects/bbox.h>

BBox::BBox() {
	pmin = Point(-INFINITY, -INFINITY, -INFINITY);
	pmax = Point(INFINITY, INFINITY, INFINITY);
}

BBox::BBox(const Point &min, const Point &max) {
	pmin = min;
	pmax = max;
}

bool BBox::intersects(const Ray &ray) const {
	if (ray.origin[0] < pmax[0] && ray.origin[0] > pmin[0] && ray.origin[1] < pmax[1] && ray.origin[1] > pmin[1] && ray.origin[1] < pmax[1] && ray.origin[1] > pmin[1]) {
		return true;
	}

	/* yet to be implemented */
	Real t, A;

	Real A0 = pmax(0) - pmin(0);
	Real A1 = pmax(1) - pmin(1);
	Real A2 = pmax(2) - pmin(2);

	if (A0 == 0. || A1 == 0. || A2 == 0.)  {
		printf("Error: Invalid bounding box.");
		return false;
	}
	
	A = A1 / A0;
	t = pmin(1) - ray.origin(1) + (ray.origin(0) - pmin(0)) * A;
	t /= (ray.direction(1) - ray.direction(0)*A);

	if (t >= ray.t_min && t <= ray.t_max) {
		return true;
	}
	return false;
}

void BBox::merge(const BBox &bbox) {
	for (int i = 0; i < 3; ++i) {
		if (bbox.pmin(i) < pmin(i))
			pmin(i) = bbox.pmin(i);
		if (bbox.pmax(i) > pmax(i))
			pmax(i) = bbox.pmax(i);
	}
}

void BBox::merge(const Point &point) {
	pmin(0) = std::min(pmin(0), point(0));
	pmin(1) = std::min(pmin(1), point(1));
	pmin(2) = std::min(pmin(2), point(2));
	pmax(0) = std::max(pmax(0), point(0));
	pmax(1) = std::max(pmax(1), point(1));
	pmax(2) = std::max(pmax(2), point(2));
}