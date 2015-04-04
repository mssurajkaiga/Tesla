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
public:
	int *indices; // array of indices
	Vertex *vertices; //array of vertices
	Triangle *cache;

	TriangleMesh(int nv = 0, int nt = 0, int *ind = NULL, Vertex *ver = NULL, Material *mat = NULL, bool il = false);

	bool intersects(const Ray &ray, Intersection* inter) const;
	void setBBox();

	friend std::ostream& operator<<(std::ostream &os, Object &o);
};

#endif