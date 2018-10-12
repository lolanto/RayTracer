#ifndef TEXTURE_H
#define TEXTURE_H

#include "RayTracer/Color.h"
#include "RayTracer/Hitable.h"

class Texture {
public:
	Texture() = default;
	virtual Color3 get_color(const Hit_record& rec) const = 0;
	virtual ~Texture() {}
};
#endif // !TEXTURE_H

