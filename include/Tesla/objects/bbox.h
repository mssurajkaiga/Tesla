#ifndef BBOX_H
#define BBOX_H

#include <Tesla/core/ray.h>
#include <vector>

/*
Axis-aligned bounding box for primary intersection tests
*/
class BBox {
public:
	Point pmin, pmax;

	BBox();
	BBox(const Vector3f &min, const Vector3f &max);

	bool intersects(const Ray &ray) const;
	void merge(const BBox &bbox);
	void merge(const Point &point);

	friend std::ostream& operator<<(std::ostream &os, BBox &b) {
		return os << "BBox(" << b.pmin << ", " << b.pmax << ")";
	}
};

#endif