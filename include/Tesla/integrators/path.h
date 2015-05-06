#ifndef PATH_H
#define PATH_H

#include <Tesla/core/core.h>
#include <Tesla/objects/vertex.h>
#include <vector>

/*
Represents a vertex on a path; only surface vertices supported now.
Position, Normal and the object/light on which the point resides.
Pdf represents the pdf with which the next edge was generated.
Apdf represents any additional pdfs computed such as from russian roulette termination.
Can also be created from an intersection.
*/
class PathVertex : public Vertex {
public:
	Real pdf, apdf;

	PathVertex(Point pos, Vector3f nor = Vector3f(0., 0., 0.), Object *obj = NULL, Real p = 1., Real ap = 1.) : Vertex(pos, nor, obj), pdf(p), apdf(ap) {}
	PathVertex(Intersection* inter, Real p = 1., Real ap = 1.) : Vertex(inter->point, inter->normal, inter->object), pdf(p), apdf(ap) {}

	inline friend std::ostream& operator<<(std::ostream &os, PathVertex &v){
		if (v.object)
			return os << "PathVertex(" << v.position << ", " << v.normal << ", " << *(v.object) << ", " << v.pdf << ", " << v.apdf << ")";
		else 
			return os << "PathVertex(" << v.position << ", " << v.normal << ", No Object, " << v.pdf << ", " << v.apdf << ")";
	}
};

/* Easy abstraction for handling rays in paths */
struct Edge {
	PathVertex *begin, *end;
	Vector3f direction;
	Edge(PathVertex* b, PathVertex* e) : begin(b), end(e) { 
		direction = end->position - begin->position; 
	}
};

/* Represents an ordered set of vertices */
class Path {
protected:
	std::vector<PathVertex> vertices;
	std::vector<PathVertex>::iterator forwarditerator;
	std::vector<PathVertex>::reverse_iterator backwarditerator;
public:
	Path() { vertices.clear(); }
	Path(std::vector<PathVertex> ver) : vertices(ver) { reset_iterator(); }

	inline void add_vertex(PathVertex &vertex) {
		vertices.push_back(vertex);
		reset_iterator(); // reallocation may have occured and iterator may be invalidated after push_back, so reset it
	}

	inline void pop_vertex() {
		bool reset = false;
		if (forwarditerator != vertices.end() && next(forwarditerator) == vertices.end()) // if iterator pointed to element being popped, reset it
			reset = true;
		vertices.pop_back();
		if (reset)
			reset_iterator();
		else
			backwarditerator = vertices.rbegin();
	}

	inline PathVertex* get_vertex_forward() {
		if (forwarditerator != vertices.end()) {
			PathVertex &v = *forwarditerator;
			++forwarditerator;
			return &v;
		}
		return NULL;
	}

	inline Edge* get_edge_forward() {
		PathVertex *v1, *v2;
		if ((v1 = get_vertex_forward()) && (v2 = get_vertex_forward())) {
			return new Edge(v1, v2);
		}
		return NULL;
	}

	inline PathVertex* get_vertex_backward() {
		if (backwarditerator != vertices.rend()) {
			PathVertex &v = *backwarditerator;
			++backwarditerator;
			return &v;
		}
		return NULL;
	}

	inline Edge* get_edge_backward() {
		PathVertex *v1, *v2;
		if ((v1 = get_vertex_backward()) && (v2 = get_vertex_backward())) {
			return new Edge(v1, v2);
		}
		return NULL;
	}

	inline unsigned int length() { // returns the number of edges in the path
		return vertices.size() - 1;
	}

	inline void reset_iterator() {
		forwarditerator = vertices.begin();
		backwarditerator = vertices.rbegin();
	}

	inline friend std::ostream& operator<<(std::ostream &os, Path &p){
		os << "Path(";
		std::vector<PathVertex>::iterator it2 = p.forwarditerator;
		p.reset_iterator();
		while(p.forwarditerator != p.vertices.end()) {
			os << *(p.forwarditerator) << ", ";
			++p.forwarditerator;
		}
		os << ")";
		p.forwarditerator = it2;
		return os;
	}
};

#endif