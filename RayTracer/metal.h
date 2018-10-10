#ifndef METAL_H
#define METAL_H
#include "material.h"

class metal :public material {
public:
	metal(const vec3& a):albedo(a) {}
	bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
	vec3 albedo;
};
#endif // !METAL_H

