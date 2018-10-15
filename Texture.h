#ifndef TEXTURE_H
#define TEXTURE_H

#include "RayTracer/Color.h"
#include "RayTracer/Hitable.h"

class Texture {
public:
	Texture() = default;
	Texture(const Texture& texture);
	virtual Texture* clone(void) const = 0;
	virtual Color3 get_color(const Hit_record& rec) const = 0;
	virtual ~Texture() {}

protected:
	Texture& operator= (const Texture& rhs);
};
#endif // !TEXTURE_H

