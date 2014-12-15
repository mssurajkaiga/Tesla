#ifndef OBJECT_H
#define OBJECT_H

#include <Tesla/core/core.h>
#include <Tesla/core/intersection.h>
#include <Tesla/core/ray.h>
#include <Tesla/materials/material.h>	
#include <Tesla/objects/bbox.h>

class Object {
	protected:
		Material material;
		BBox bbox;

	public:
		Object();

		virtual bool intersects(const Ray &ray, Intersection* inter) const = 0;

		Material* getMaterial();
		const Material* getMaterial() const;
		virtual bool isLight() const;

		virtual BBox* getBBox() = 0;
		virtual void setBBox() = 0;
		virtual Vector3f sample() const = 0;
};

#endif