#ifndef BBOX_H
#define BBOX_H

#include <Tesla/core/intersection.h>
#include <Tesla/core/ray.h>
#include <vector>

class BBox {
public:
	Vector3f pmin, pmax;

	BBox();
	BBox(const Vector3f &min, const Vector3f &max);

	bool intersects(const Ray &ray);

};

class BBoxNode {
private:
	BBox bbox;
	std::vector<BBoxNode*> children;
	std::vector<Object*> objects;
public:
	BBoxNode(const BBox &bbox);
	~BBoxNode();
	
	bool intersection(const Ray &ray, Intersection* inf) const;
	void add_child(BBoxNode* node);
	void add_object(Object* obj);
};

#endif