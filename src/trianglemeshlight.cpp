#include <Tesla/lights/trianglemeshlight.h>
#include <Tesla/lights/trianglelight.h>

TriangleMeshLight::TriangleMeshLight(int nv, int nt, int *ind, Vertex *ver, bool il) : Light(), numvertices(nv), numtriangles(nt) {
	for (int i = 0; i < nv; i++) {
		vertices[i].object = (TriangleMeshLight*) this;
	}
	setBBox();
}

void TriangleMeshLight::setBBox() {
	bbox = BBox(Point(0., 0., 0.), Point(0., 0., 0.));
	for (int i = 0; i < numvertices; i++) {
		bbox.merge(vertices[i].position);
	}
}

bool TriangleMeshLight::intersects(const Ray &ray, Intersection* inter) const {
	/* the first time its called, generate all triangles and cache it for reuse */
	if (!cache) {
		(TriangleLight*)(this->cache) = new TriangleLight[numtriangles];
		for (int i = 0; i < numtriangles; i++)
			cache[i] = TriangleLight((TriangleMeshLight*)this, &indices[3 * i]);
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
			inter->object = (TriangleMeshLight*)this;
		}
		return true;
	}

	return false;
}