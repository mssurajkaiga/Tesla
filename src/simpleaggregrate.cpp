#include <Tesla/objects/simpleaggregrate.h>

void SimpleAggregrate::add(Object* object) {
	objects.push_back(object);
	setBBox(object);
}

void SimpleAggregrate::add(Light* light) {
	lights.push_back(light);
}

bool SimpleAggregrate::intersects(const Ray &ray, Intersection* inter) {
	Intersection in, temp;
	in.t = INFINITY;
	bool intersected = false;
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		if ((*i)->intersects(ray, &temp)) {
			if (temp.t < in.t) {
				in = temp;
				intersected = true;
			}
		}
	}

	for (auto i = lights.begin(); i != lights.end(); i++) {
		if ((*i)->intersects(ray, &temp)) {
			if (temp.t < in.t) {
				in = temp;
				intersected = true;
			}
		}
	}
	
	if (intersected) {
		if (inter)
			inter->copy(in);
		return true;
	}
	return false;
}

void SimpleAggregrate::setBBox() {
	std::vector<Object*>::iterator i = objects.begin();
	bbox = *((*i)->getBBox());
	for (; i != objects.end(); ++i) {
		setBBox((*i));
	}
}

void SimpleAggregrate::setBBox(Object* object) {
	BBox* b = object->getBBox();
	bbox.merge(*b);
}