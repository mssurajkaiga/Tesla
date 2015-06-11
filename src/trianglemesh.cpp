#include <Tesla/objects/trianglemesh.h>
#include <Tesla/objects/triangle.h>

TriangleMesh::TriangleMesh(int nv, int nt, int *ind, Vertex *ver, Material *mat, LightSource *l) : Object(mat, l), numvertices(nv), numtriangles(nt) {
	for (int i = 0; i < nv; i++) {
		vertices[i].object = (TriangleMesh*) this;
	}
	cache = NULL;
	setBBox();
}

TriangleMesh::~TriangleMesh() {
	if (cache) {
		delete[] cache;
	}
}

void TriangleMesh::setBBox() {
	bbox = BBox(Point(0., 0., 0.), Point(0., 0., 0.));
	for (int i = 0; i < numvertices; i++) {
		bbox.merge(vertices[i].position);
	}
}

bool TriangleMesh::intersects(const Ray &ray, Intersection* inter) const {
	/* the first time its called, generate all triangles and cache it for reuse */
	if (!cache) {
		generateCache();
	}

	Intersection in, temp;
	in.t = INFINITY;
	bool intersected = false;
	for (int i = 0; i < numtriangles; i++) {
		if (cache[i].intersects(ray, &temp)) {
			if (temp.t < in.t) {
				in = temp;
				intersected = true;
			}
		}
	}

	if (intersected) {
		if (inter) {
			inter->copy(in);
			inter->object = (TriangleMesh*)this;
		}
		return true;
	}

	return false;
}

void TriangleMesh::generateCache() const {
	area = 0.;
	(Triangle*)(this->cache) = new Triangle[numtriangles];
	for (int i = 0; i < numtriangles; i++) {
		cache[i] = Triangle((TriangleMesh*)this, &indices[3 * i]);
		area += cache[i].getArea();
	}
}

Real TriangleMesh::getArea() const{
	if (!cache)
		generateCache();
	return area;
}