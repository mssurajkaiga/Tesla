#include <Tesla/cameras/camera.h>

Camera::Camera() {
	position = Point(0., 0., 0.);
	lookat = Vector3f(10., 10., 10.);
}

Camera::Camera(const Vector3f &pos, const Vector3f &look) {
	position = pos;
	lookat = look;
}

Ray generateRay(Sample sample) {
	return Ray();
}
