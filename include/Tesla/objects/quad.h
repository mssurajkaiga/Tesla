#ifndef QUAD_H
#define QUAD_H

#include <Tesla/objects/trianglemesh.h>

/* 
Represents a quad - triangle mesh of four vertices.
Order of the four vertices specify normal using right hand rule.
*/
class Quad : public TriangleMesh {
public:
	Quad(Point a, Point b, Point c, Point d, Material *mat = NULL, LightSource *l = NULL);
};

#endif
