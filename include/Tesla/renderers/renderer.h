#ifndef RENDERER_H
#define RENDERER_H

#include <Tesla/core/core.h>
#include <Tesla/core/scene.h>

class Renderer
{
public:
	virtual void render(const Scene *scene) = 0;
};

#endif