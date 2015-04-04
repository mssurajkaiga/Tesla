#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <Tesla/util/exr.h>

class ImageWriter {
public:
	enum Type {PNG, BMP, TGA, HDR, EXR};
	inline bool write(std::string filename, int width, int height, int channels, float* data, Type t, int stride_in_bytes = 0) {
		switch (t) {
		case PNG:
			return stbi_write_png(filename.append(".png").c_str(), width, height, channels, data, stride_in_bytes);

		case BMP:
			return stbi_write_bmp(filename.append(".bmp").c_str(), width, height, channels, data);

		case TGA:
			return stbi_write_tga(filename.append(".tga").c_str(), width, height, channels, data);

		case HDR:
			return stbi_write_hdr(filename.append(".hdr").c_str(), width, height, channels, data);

		case EXR:
			return exr.write(filename, width, height, channels, data);

		default:
			return false;
		}
	}
};

static ImageWriter iw;
#endif