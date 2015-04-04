#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include <Tesla/cameras/camera.h>

/* Perspective camera
dof: distance from camera along -z(camera coordinates) where the image plane is located
fovx, fovy: defines field of view along x,y directions
position, target, up - define coordinate system of camera
*/

class PerspectiveCamera: public Camera
{
	enum Type { PINHOLE, FINITE_APERTURE };
private:
	Real aperture, dof, fovx, fovy;
	Type type;
public:
	PerspectiveCamera() : Camera(), aperture(0.), dof(1.), type(PINHOLE) {}
	PerspectiveCamera(const Vector3f &pos, const Vector3f &look, const Vector3f &u) : Camera(pos, look, u), aperture(0.), dof(1.), type(PINHOLE), fovx(1.), fovy(1.) {}
	PerspectiveCamera(const Vector3f &pos, const Vector3f &look, const Vector3f &u, Real a, Real d, Real fx, Real fy);
	Ray generateRay(ImageSampler* imagesampler, ImageSample* imagesample) const; //generate ray from a sample position on image plane
};

#endif