#include <Tesla/cameras/perspectivecamera.h>

PerspectiveCamera::PerspectiveCamera(const Vector3f &pos, const Vector3f &target, const Vector3f &u, Real a, Real d, Real fx, Real fy) : Camera(pos, target, u), aperture(a), dof(d), fovx(fx), fovy(fy) {
	if (aperture > 0. && dof > 0.) {
		type = FINITE_APERTURE;
	}
	else
		type = PINHOLE;
}

Ray PerspectiveCamera::generateRay(ImageSampler* imagesampler, ImageSample *imagesample) const {
	Ray r;
	switch (type) {
	case FINITE_APERTURE:
		// to do
		//break;
	case PINHOLE:
		r.origin = position;
		r.direction = (imagesample->x/imagesampler->xmax - 0.5) * fovx * x + (imagesample->y/imagesampler->ymax - 0.5) * fovy * y  - dof * z; //to-do optimize
		r.direction.normalize();
		break;
	}

	return r;
}