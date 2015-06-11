#ifndef RENDERER_H
#define RENDERER_H

#include <Tesla/core/core.h>
#include <Tesla/core/scene.h>
#include <Tesla/films/film.h>
#include <Tesla/cameras/camera.h>

class Renderer
{
protected:
	Film *film;
	
public:
	Renderer(Film* film) : film(film) {}
	virtual void render(Scene *scene, Camera *camera) = 0;
};

#endif