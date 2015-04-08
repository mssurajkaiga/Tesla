#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/trianglemesh.h>

/*
Represents a simple triangle in terms of triangle mesh vertex indices
*/
class Triangle : public Object {
protected:
	TriangleMesh* trianglemesh;
	int *indices; // array of indices

public:
	Triangle(TriangleMesh* mesh = NULL, int *i = NULL) : trianglemesh(mesh), indices(i) { setBBox();}
	bool intersects(const Ray &ray, Intersection* inter) const;
	void setBBox();
	Real getArea() const;
	Spectrum getSample(const Vector3f &point, Point &sample, Real &pdf) const;
};

#endif