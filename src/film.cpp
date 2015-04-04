#include <Tesla/films/film.h>
#include <Tesla/util/imagewriter.h>

void Film::store(std::vector<Spectrum> d) {
	data = new float[d.size() * 3];
	int i = 0;
	auto it = d.begin();
	while(it != d.end() && i < d.size() * 3) {
		data[i] = (*it)(0);
		data[i + 1] = (*it)(1);
		data[i + 2] = (*it)(2);
		++it;
		i += 3;
	}
}

bool Film::save(std::string filename, mode m) {
	switch (m) {
	case EXR:
		return iw.write(filename, x, y, CRS, data, ImageWriter::EXR);

	case HDR:
		return iw.write(filename, x, y, CRS, data, ImageWriter::HDR);

	default:
		return false;
	}
}