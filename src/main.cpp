//disable Qt interface for now
//#include "app.h"
#include <Tesla/core/core.h>
#include <Tesla/core/randomizer.h>
#include <Tesla/integrators/ptintegrator.h>
#include <Tesla/renderers/pathtracer.h>
#include <Tesla/core/scene.h>
#include <Tesla/objects/sphere.h>
#include <Tesla/objects/quad.h>
#include <Tesla/objects/simpleaggregrate.h>
#include <Tesla/lights/pointlightsource.h>
#include <Tesla/lights/quadlight.h>
#include <Tesla/cameras/perspectivecamera.h>
#include <Tesla/materials/mattematerial.h>
#include <Tesla/materials/mirrormaterial.h>
#include <Tesla/samplers/stratifiedimagesampler.h>
#include <Tesla/films/film.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    /*
	App app(argc,argv);
    return app.exec();
	*/

	/* Default scene*/
	int width = 100, height = 100, spp = 4;
	bool jitter = false;
	std::string filename = "output";
	Scene scene;
	Camera *camera = NULL;
	int mindepth = 2, maxdepth = 5;
	TerminationCriterion tc = RUSSIAN_ROULETTE;
	Illumination ill = GLOBAL;

	if (argc < 2) {
		MatteMaterial mm1(Spectrum(1.0, 0.0, 0.0));
		MatteMaterial mm2(Spectrum(0., 1.0, 1.0));

		Sphere sph1(Vector3f(0., 0., -15.), 3.0);
		sph1.setMaterial(&mm1);
		scene.add(&sph1);

		Sphere sph2(Vector3f(-4., 2., -9.), 3.0);
		sph2.setMaterial(&mm2);
		scene.add(&sph2);

		scene.add(new PointLightSource(Vector3f(-4., 7., -9.), Spectrum(1.0, 1.0, 1.0), 100.));
	}
	
	else {
		std::string toparse;
		for (int i = 1; i < argc; ++i) {
			toparse = std::string(argv[i]);

			if (toparse == "-maxdepth") {
				maxdepth = atoi(argv[++i]);
			}

			if (toparse == "-mindepth") {
				mindepth = atoi(argv[++i]);
			}

			if (toparse == "-russianroulette") {
				tc = RUSSIAN_ROULETTE;
			}

			if (toparse == "-direct") {
				ill = DIRECT;
			}

			if (toparse == "-indirect") {
				ill = INDIRECT;
			}

			if (toparse == "-width") {
				width = atoi(argv[++i]);
			}

			if (toparse == "-height") {
				height = atoi(argv[++i]);
			}

			if (toparse == "-spp") {
				spp = atoi(argv[++i]);
			}

			if (toparse == "-jitter") {
				jitter = atoi(argv[++i]);
			}

			if (toparse == "-sphere") {
				++i;
				Sphere *sphere = new Sphere(Vector3f(atof(argv[i]), atof(argv[i + 1]), atof(argv[i + 2])), atof(argv[i + 3]));
				i += 4;
				toparse = std::string(argv[i]);
				if (toparse == "-rgb" || toparse == "-rgb-matte") {
					MatteMaterial *mm = new MatteMaterial(Spectrum(atof(argv[i + 1]), atof(argv[i + 2]), atof(argv[i + 3])));
					sphere->setMaterial(mm);
					i += 3;
				}
				else if (toparse == "-rgb-mirror") {
					MirrorMaterial *mm = new MirrorMaterial(Spectrum(atof(argv[i + 1]), atof(argv[i + 2]), atof(argv[i + 3])));
					sphere->setMaterial(mm);
					i += 3;
				}
				else {
					MatteMaterial *mm = new MatteMaterial(Spectrum(1.0, 1.0, 1.0));
					sphere->setMaterial(mm);
					--i;
				}
				scene.add(sphere);
			}

			if (toparse == "-quad") {
				++i;
				Quad *quad = new Quad(Vector3f(atof(argv[i]), atof(argv[i + 1]), atof(argv[i + 2])), Vector3f(atof(argv[i + 3]), atof(argv[i + 4]), atof(argv[i + 5])), Vector3f(atof(argv[i + 6]), atof(argv[i + 7]), atof(argv[i + 8])), Vector3f(atof(argv[i + 9]), atof(argv[i + 10]), atof(argv[i + 11])));
				i += 12;
				toparse = std::string(argv[i]);
				if (toparse == "-rgb") {
					MatteMaterial *mm = new MatteMaterial(Spectrum(atof(argv[i + 1]), atof(argv[i + 2]), atof(argv[i + 3])));
					quad->setMaterial(mm);
					i += 3;
				}
				else {
					MatteMaterial *mm = new MatteMaterial(Spectrum(1.0, 1.0, 1.0));
					quad->setMaterial(mm);
					--i;
				}
				scene.add(quad);
			}

			if (toparse == "-pointlightsource") {
				++i;
				PointLightSource *lightsource = new PointLightSource(Vector3f(atof(argv[i]), atof(argv[i + 1]), atof(argv[i + 2])), Spectrum(atof(argv[i + 3]), atof(argv[i + 4]), atof(argv[i + 5])), atof(argv[i + 6]));
				i += 6;
				scene.add(lightsource);
			}

			if (toparse == "-quadlight") {
				++i;
				QuadLight *light = new QuadLight(Vector3f(atof(argv[i]), atof(argv[i + 1]), atof(argv[i + 2])), Vector3f(atof(argv[i + 3]), atof(argv[i + 4]), atof(argv[i + 5])), Vector3f(atof(argv[i + 6]), atof(argv[i + 7]), atof(argv[i + 8])), Vector3f(atof(argv[i + 9]), atof(argv[i + 10]), atof(argv[i + 11])), Spectrum(atof(argv[i + 12]), atof(argv[i + 13]), atof(argv[i + 14])), atof(argv[i + 15]));
				i += 15;
				scene.add(light);
			}

			if (toparse == "-filename") {
				filename = std::string(argv[++i]);
			}

			if (toparse == "-perspectivecamera") {
				++i;
				camera = new PerspectiveCamera(Vector3f(atof(argv[i]), atof(argv[i + 1]), atof(argv[i + 2])), Vector3f(atof(argv[i + 3]), atof(argv[i + 4]), atof(argv[i + 5])), Vector3f(atof(argv[i + 6]), atof(argv[i + 7]), atof(argv[i + 8])), atof(argv[i + 9]), atof(argv[i + 10]), atof(argv[i + 11]), atof(argv[i + 12]));
				i += 12;
			}

		}
	}

	if (!camera){
		camera = new PerspectiveCamera(Vector3f(0., 0., 0.), Vector3f(0., 0., -3), Vector3f(0., 1., 0.), 0., 3., 5., 5.);
	}

	StratifiedImageSampler sis(0, width, 0, height, spp, jitter);
	Film film(width, height, NULL);
	PTIntegrator pti(mindepth, maxdepth, tc, ill);
	PathTracer pt(&sis, &pti, &film);
	pt.render(&scene, camera);
	film.save(filename, Film::HDR);
	return 0;
}