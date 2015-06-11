#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include <Tesla/objects/object.h>
#include <Tesla/objects/vertex.h>

extern class Triangle;
/*
Represents a simple mesh of triangles
*/
class TriangleMesh : public Object {
protected:
	int numvertices, numtriangles;
	mutable Real area;
	void generateCache() const;
public:
	int *indices; // array of indices
	Vertex *vertices; //array of vertices
	Triangle *cache;

	TriangleMesh(int nv = 0, int nt = 0, int *ind = NULL, Vertex *ver = NULL, Material *mat = NULL, LightSource *l = NULL);
	~TriangleMesh();

	bool intersects(const Ray &ray, Intersection* inter) const;
	void setBBox();
	Real getArea() const;

	friend std::ostream& operator<<(std::ostream &os, Object &o);
};

#endif