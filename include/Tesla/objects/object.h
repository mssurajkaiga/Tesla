#ifndef OBJECT_H
#define OBJECT_H

#include <Tesla/core/core.h>
#include <Tesla/core/ray.h>
#include <Tesla/core/intersection.h>
#include <Tesla/materials/material.h>	
#include <Tesla/objects/bbox.h>
#include <Tesla/bsdfs/bsdf.h>

/* Represents an object.
An object may be associated with a light in which case the islight flag is set to true.
*/
class Object {
	protected:
		Material* material;
		BBox bbox;
		bool islight;

	public:
		Object(Material *mat = NULL, bool il = false) : islight(il), material(mat) { setBBox(); }
		virtual bool intersects(const Ray &ray, Intersection* inter) const = 0;

		void setMaterial(Material *mat);
		Material* getMaterial(Intersection* inter) const;
		Material* getMaterial();
		bool isLight() const;

		BBox* getBBox();
		virtual void setBBox() { bbox = BBox(); };

		friend std::ostream& operator<<(std::ostream &os, Object &o);
};

#endif