#ifndef VERTEX_H
#define VERTEX_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>

/*
Represents a general vertex
*/

class Vertex {
public:
	Point position;
	Vector3f normal;
	Object* object;
	Vertex() {}
	Vertex(Point pos, Vector3f nor = Vector3f(0., 0., 0.), Object *obj = NULL) : position(pos), normal(nor), object(obj) {}

	inline friend std::ostream& operator<<(std::ostream &os, Vertex &v){
		if (v.object)
			return os << "Vertex(" << v.position << ", " << v.normal << ", " << *(v.object) << ")";
		else
			return os << "Vertex(" << v.position << ", " << v.normal << ", No Object)";
	}
};

#endif