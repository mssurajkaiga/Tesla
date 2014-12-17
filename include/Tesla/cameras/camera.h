#ifndef CAMERA_H
#define CAMERA_H

#include <Tesla/core/ray.h>
#include <Tesla/core/sample.h>

class Camera
{
private:
	Vector3f position, lookat;

public:
	Camera();
	Camera(const Vector3f &pos, const Vector3f &look);
	Ray generateRay(Sample sample);
};

#endif