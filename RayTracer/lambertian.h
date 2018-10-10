#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#include "material.h"

class lambertian :public material {
public:
	lambertian(const vec3& a):albedo(a) {}
	bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered)const;
	vec3 albedo;
};
#endif // !LAMBERTIAN_H

