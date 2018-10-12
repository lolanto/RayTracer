#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#include "Material.h"

class Lambertian :public Material {
public:
	Lambertian(const Vec3& a):albedo(a) {}
	bool scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered)const;
	Vec3 albedo;
};

Vec3 random_in_unit_Sphere();

#endif // !LAMBERTIAN_H

