#ifndef METAL_H
#define METAL_H
#include "Material.h"

class Metal :public Material {
public:
	Metal(const Vec3& a):albedo(a) {}
	Metal(const Vec3& a, float f) :albedo(a) { if (f < 1) fuzz = f; else fuzz = 1; }
	bool scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const;
	Vec3 albedo;
	float fuzz;
};
Vec3 reflect(const Vec3& v, const Vec3& n);
#endif // !METAL_H

