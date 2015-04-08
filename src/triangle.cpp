#include <Tesla/objects/triangle.h>
#include <Tesla/core/randomizer.h>

/* Shamelessly copied from pbrt! I'm very very shameless!! */

bool Triangle::intersects(const Ray &ray, Intersection* inter) const {
	Point p1 = trianglemesh->vertices[indices[0]].position;
	Point p2 = trianglemesh->vertices[indices[1]].position;
	Point p3 = trianglemesh->vertices[indices[2]].position;

	Vector3f e1 = p2 - p1;
	Vector3f e2 = p3 - p1;
	Vector3f s1 = ray.direction.cross(e2);
	Real d = s1.dot(e1);

	if (d == 0.)
		return false;

	Real invd = 1. / d;

	Vector3f t = ray.origin - p1;
	Real b1 = t.dot(s1) * invd;
	if (b1 < 0. || b1 > 1.)
		return false;

	Vector3f s2 = t.cross(e1);
	Real b2 = ray.direction.dot(s2) * invd;
	if (b2 < 0. || b1 + b2 > 1.)
		return false;

	Real t_hit = e2.dot(s2) * invd;

	if (t_hit < ray.t_min || t_hit > ray.t_max) {
		return false;
	}

	/* Successful intersection */
	inter->t = t_hit;
	// normal is interpolated using barycentric coordinates
	inter->normal = (1 - b1 - b2) * trianglemesh->vertices[indices[0]].normal + b1 * trianglemesh->vertices[indices[1]].normal + b2 * trianglemesh->vertices[indices[2]].normal;
	inter->normal.normalize(); // just in case, (to do - needs to be removed eventually)
	inter->object = (Triangle*) this;
	inter->point = ray.origin + t_hit * ray.direction;
	return true;
}

void Triangle::setBBox() {
	if (!trianglemesh)
		return;
	bbox = BBox(trianglemesh->vertices[indices[0]].position, trianglemesh->vertices[indices[1]].position);
	bbox.merge(trianglemesh->vertices[indices[2]].position);
}

Real Triangle::getArea() const {
	if (!trianglemesh)
		return 0.;
	Point p1 = trianglemesh->vertices[indices[0]].position;
	Point p2 = trianglemesh->vertices[indices[1]].position;
	Point p3 = trianglemesh->vertices[indices[2]].position;

	return 0.5f * (p2 - p1).cross(p3 - p1).norm();
}

Spectrum Triangle::getSample(const Vector3f &point, Point &sample, Real &pdf) const {
	Point p1 = trianglemesh->vertices[indices[0]].position;
	Point p2 = trianglemesh->vertices[indices[1]].position;
	Point p3 = trianglemesh->vertices[indices[2]].position;

	/* generate uniformly distributed sample using barycentric coordinates */

	Real b1 = 1 - sqrtf(ung.generateRandom());
	Real b2 = 1 - sqrtf(ung.generateRandom());

	sample = (1 - b1 - b2)*p1 + b1 * p2 + b2 * p3;
	pdf = 1. / getArea();
	return Spectrum(0., 0., 0.);
}