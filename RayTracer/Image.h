#ifndef IMAGE_H
#define IMAGE_H
#include "Color.h"
#include <vector>
class Image {
public:
	Image() = default;
	Image(int h, int v);
	Image(const Image& image);
	Image& operator= (const Image& image);
	~Image() {}
	void read_ppm_file(const char* filename);
	int get_hres();
	int get_vres();
	Color3 get_color(const int row, const int col) const;
private:
	int hres;
	int vres;
	std::vector<Color3> pixels;
};

inline 
int Image::get_hres(void) {
	return (hres);
}
inline 
int Image::get_vres(void) {
	return (vres);
}

#endif // !IMAGE_H
