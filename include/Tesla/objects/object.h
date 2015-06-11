#ifndef OBJECT_H
#define OBJECT_H

#include <Tesla/core/core.h>
#include <Tesla/core/ray.h>
#include <Tesla/core/intersection.h>
#include <Tesla/materials/material.h>
#include <Tesla/lights/lightsource.h>
#include <Tesla/objects/bbox.h>
#include <Tesla/bsdfs/bsdf.h>

/* Represents an object.
An object may have a light attached to it in which case the islight flag is set to true.
*/
class Object {
	protected:
		std::string id;
		Material* material;
		BBox bbox;
		bool islight;
		LightSource *lightsource;

	public:
		Object(Material *mat = NULL, LightSource* l = NULL);
		Object(std::string id = "", Material *mat = NULL, LightSource* l = NULL);
		virtual bool intersects(const Ray &ray, Intersection* inter) const = 0;
		virtual Spectrum getSample(const Point &point, Point &sample, Real &pdf) const { return Spectrum(0.); }; //sample a position on the object and return emitted radiance

		void setMaterial(Material *mat);
		void setId(std::string id);
		Material* getMaterial(Intersection* inter) const;
		Material* getMaterial();
		bool isLight() const;
		LightSource* getLightSource() const;

		BBox* getBBox();
		virtual void setBBox() { bbox = BBox(); };

		friend std::ostream& operator<<(std::ostream &os, Object &o);
};

#endif