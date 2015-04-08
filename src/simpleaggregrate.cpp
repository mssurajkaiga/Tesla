#include <Tesla/objects/simpleaggregrate.h>

void SimpleAggregrate::add(Object* object) {
	if (object->isLight())
		lights.push_back(object);
	else
		objects.push_back(object);
	setBBox(object);
}

void SimpleAggregrate::add(LightSource* lightsource) {
	lightsources.push_back(lightsource);
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
	auto i = objects.begin();
	bbox = *((*i)->getBBox());
	for (; i != objects.end(); ++i) {
		setBBox((*i));
	}
}

void SimpleAggregrate::setBBox(Object* object) {
	BBox* b = object->getBBox();
	bbox.merge(*b);
}

int SimpleAggregrate::getNumObjects() const {
	return objects.size();
}

int SimpleAggregrate::getNumLights() const {
	return lights.size();
}

int SimpleAggregrate::getNumLightSources() const {
	return lightsources.size();
}

LightSource* SimpleAggregrate::getLightSource(Real &pdf) const {
	if (!lightsources.empty()) {
		pdf = 1. / lightsources.size();
		return lightsources[rand() % lightsources.size()];
	}
	return NULL;
}

Object* SimpleAggregrate::getLight(Real &pdf) const {
	if (!lights.empty()){
		pdf = 1. / lights.size();
		return lights[rand() % lights.size()];
	}
	return NULL;
}