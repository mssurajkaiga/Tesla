#include <Tesla/objects/bbox.h>

BBox::BBox() {
	pmin = Vector3f(-INFINITY, -INFINITY, -INFINITY);
	pmax = Vector3f(INFINITY, INFINITY, INFINITY);
}

BBox::BBox(const Vector3f &min, const Vector3f &max) {
	pmin = min;
	pmax = max;
}

bool BBox::intersects(const Ray &ray) {
	if (ray.origin[0] < pmax[0] && ray.origin[0] > pmin[0] && ray.origin[1] < pmax[1] && ray.origin[1] > pmin[1] && ray.origin[1] < pmax[1] && ray.origin[1] > pmin[1]) {
		return true;
	}

	/* yet to be implemented */
	return false;
}