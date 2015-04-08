#include <Tesla/objects/quad.h>

Quad::Quad(Point a, Point b, Point c, Point d, Material *mat, LightSource *l) {
	numvertices = 4;
	numtriangles = 2;
	indices = new int[6];
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;
	vertices = new Vertex[4];
	Vector3f normal = (b - a).cross(b - c);
	normal.normalize();
	vertices[0] = Vertex(a, normal, this);
	vertices[1] = Vertex(b, normal, this);
	vertices[2] = Vertex(c, normal, this);
	vertices[3] = Vertex(d, normal, this);
	material = mat;
	lightsource = l;
	if (lightsource)
		islight = true;
	else
		islight = false;
}