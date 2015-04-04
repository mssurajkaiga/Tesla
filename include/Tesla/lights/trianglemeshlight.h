#ifndef TRIANGLEMESHLIGHT_H
#define TRIANGLEMESHLIGHT_H

#include <Tesla/lights/light.h>
#include <Tesla/objects/vertex.h>

extern class Triangle;
/*
Represents a simple mesh of triangles
*/
class TriangleMeshLight : public Light {
protected:
	int numvertices, numtriangles;
public:
	int *indices; // array of indices
	Vertex *vertices; //array of vertices
	Triangle *cache;

	TriangleMeshLight(int nv = 0, int nt = 0, int *ind = NULL, Vertex *ver = NULL, bool il = true);

	bool intersects(const Ray &ray, Intersection* inter) const;
	void setBBox();
};

#endif