#ifndef CAMERA_H
#define CAMERA_H

#include <Tesla/core/ray.h>
#include <Tesla/samplers/imagesample.h>
#include <Tesla/samplers/imagesampler.h>

/* Camera which looks into -z direction of its coordinate space */
class Camera
{
protected:
	Vector3f position, target, up;
	Real shutteropen, shutterclose;
	Vector3f x, y, z; // coordinate system of camera in world-space directions

public:
	Camera() : position(Vector3f(0., 0., 0.)), target(Vector3f(0., 0., 1.)), up(Vector3f(0., 1., 0.)) { setup(); }
	Camera(const Vector3f &pos, const Vector3f &t, const Vector3f &u) : position(pos), target(t), up(u) { setup(); }
	inline void setup() {
		y = up;
		z = position - target;
		x = y.cross(z);
		y = z.cross(x); // to correct for any slope between up vector and x 
		x.normalize();
		y.normalize();
		z.normalize();
	}
	virtual Ray generateRay(ImageSampler* imagesampler, ImageSample* imagesample) const = 0; //generate ray from a sample position on image plane
};

#endif