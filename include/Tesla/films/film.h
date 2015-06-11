#ifndef FILM_H
#define FILM_H

#include <Tesla/core/core.h>
#include <Tesla/filters/filter.h>
#include <vector>
#include <string>

class Film {
protected:
	int x, y;
	float* data;
	Filter* filter;
public:
	/* Not in use */
	/* Data can be RGB, XYZ or any custom representation*/
	struct Pixel {
		Real data[CRS];
		inline Pixel() {
			for (int i = 0; i < CRS; ++i) {
				data[i] = 0.;
			}
		}
	};

	enum mode { EXR , HDR };
	Film(int x, int y, Filter* f) : x(x), y(y), filter(f) { data = NULL; }
	~Film() { 
		if (data) 
			delete data; 
		if (filter)
			delete filter; 
	}

	void store(std::vector<Spectrum> d);
	bool save(std::string filename, mode m);
};

#endif