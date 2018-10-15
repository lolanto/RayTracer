#ifndef HITABLE_H
#define HITABLE_H

#include <vector>
#include "Ray.h"

class Hitable;
class Material;
class ImageTexture;

struct Hit_record
{
	float t;
	Vec3 p;
	Vec3 normal;
	const Hitable* obj;
	Material* mat_ptr;
	ImageTexture* tex_ptr;
};

class Hitable {
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const = 0;
	virtual std::vector<Vec3> getAttribute() const = 0;
};
#endif // !HITABLE_H

