#include "Image.h"
#include <cstdio>

Image::Image(int h, int v) 
	: hres(h), 
	vres(v) 
{}

Image::Image(const Image& image)
	: hres(image.hres),
	vres(image.vres),
	pixels(image.pixels)
{}

Image& Image::operator= (const Image& rhs) {
	if (this == &rhs)
		return (*this);

	hres = rhs.hres;
	vres = rhs.vres;
	pixels = rhs.pixels;

	return (*this);
}
void Image::read_ppm_file(const char* filename) {

	FILE* file = fopen(filename, "rb");

	if (file == 0) {
		std::cout << "could not open file" << std::endl;
	}
	else
		std::cout << "file opened" << std::endl;


	unsigned char ppm_type;
	if (fscanf(file, "P%c\n", &ppm_type) != 1) {
		std::cout << "Invalid PPM signature" << std:: endl;
	}


	if (ppm_type != '6') {
		std::cout << "Only binary PPM supported" << std::endl;
	}


	unsigned char dummy;
	while (fscanf(file, "#%c", &dummy))
		while (fgetc(file) != '\n');


	if (fscanf(file, "%d %d\n", &hres, &vres) != 2) {
		std::cout << "Invalid image size" << std::endl;
	}

	if (hres <= 0)
		std::cout << "Invalid image width" << std::endl;
	else
		std::cout << "hres = " << hres << std::endl;


	if (vres <= 0)
		std::cout << "Invalid image height" << std::endl;
	else
		std::cout << "vres = " << vres << std::endl;

	unsigned int max_value;
	if (fscanf(file, "%d\n", &max_value) != 1) {
		std::cout << "Invalid max value" << std::endl;
	}

	float inv_max_value = 1.0 / (float)max_value;

	pixels.reserve(hres * vres);

	for (unsigned int y = 0; y < vres; y++) {
		for (unsigned int x = 0; x < hres; x++) {
			unsigned char red;
			unsigned char green;
			unsigned char blue;

			if (fscanf(file, "%c%c%c", &red, &green, &blue) != 3) {
				std::cout << "Invalid image" << std::endl;
			}

			float r = red   * inv_max_value;
			float g = green * inv_max_value;
			float b = blue  * inv_max_value;

			pixels.push_back(Color3(r, g, b));
		}
	}

	fclose(file);

	std::cout << "finished reading PPM file" << std::endl;
}

Color3 Image::get_color(const int row, const int column) const {
	int index = column + hres * (vres - row - 1);
	int pixels_size = pixels.size();

	if (index < pixels_size)
		return (pixels[index]);
	else
		return Color3(1.0, 0.0, 0.0);    // useful for debugging 
}