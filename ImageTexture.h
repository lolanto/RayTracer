#ifndef IMAGETEXTURE_H
#define IMAGETEXTURE_H

#include "RayTracer/Image.h"
#include "RayTracer/Mapping.h"
#include "Texture.h"

class ImageTexture : Texture {
public:
	ImageTexture() = default;
	ImageTexture(Image* _image_ptr);
	ImageTexture(const ImageTexture& it);
	ImageTexture& operator= (const ImageTexture& rhs);
	virtual ImageTexture* clone(void) const;
	virtual Color3 get_color(const Hit_record& rec) const;
	void set_image(Image* _image_ptr);
	void set_mapping(Mapping* map_ptr);
	~ImageTexture();

private:
	int hres;
	int vres;
	Image* image_ptr;
	Mapping* mapping_ptr;
};

inline 
void ImageTexture::set_image(Image* _image_ptr) {
	image_ptr = _image_ptr;
	hres = image_ptr->get_hres();
	vres = image_ptr->get_vres();
}

inline 
void ImageTexture::set_mapping(Mapping* map_ptr) {
	mapping_ptr = map_ptr;
}

#endif // !IMAGETEXTURE_H
