#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "RayTracer/Material.h"
#include "RayTracer/Metal.h"

class Dielectric : public Material{
public:
	Dielectric(float ri) : ref_idx(ri) {}
	virtual bool scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const;
	float ref_idx;
};

bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted);
float schlick(float cosine, float ref_idx);

#endif // DIELECTRIC_H
