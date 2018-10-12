#ifndef MATERIAL_H
#define MATERIAL_H
#include "Hitable.h"

class Material {
public:
	virtual bool scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const = 0;
};
#endif // !MATERIAL_H

