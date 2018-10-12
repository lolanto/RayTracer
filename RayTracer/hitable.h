#ifndef HITABLE_H
#define HITABLE_H

#include "Ray.h"
class Material;

struct Hit_record
{
	float t;
	Vec3 p;
	Vec3 normal;
	Material* mat_ptr;
};

class Hitable {
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const = 0;
};
#endif // !HITABLE_H

