#include "Dielectric.h"

bool refract(const Vec3& v, const Vec3& n, float ior, Vec3& refracted) {
	Vec3 uv = unit_vector(v);
	float dt = dot(uv, n);
	float discriminat = 1.0 - ior * ior*(1 - dt * dt);
	if (discriminat > 0) {
		refracted = ior * (uv - n * dt) - n * sqrt(discriminat);
		return true;
	}
	else
		return false;
}

float schlick(float cosine, float ref_idx) {
	float r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool Dielectric::scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const {
	Vec3 outward_normal;
	Vec3 reflected = reflect(r_in.direction(), rec.normal);
	float ior;
	attenuation = Vec3(1.0, 1.0, 1.0);
	Vec3 refracted;
	float reflect_prob;
	float cosine;
	if (dot(r_in.direction(), rec.normal) > 0) {
		outward_normal = -rec.normal;
		ior = ref_idx;
	}
	else {
		outward_normal = rec.normal;
		ior = 1.0 / ref_idx;
	}
	cosine = dot(-r_in.direction(), outward_normal) / r_in.direction().length();
	if (refract(r_in.direction(), outward_normal, ior, refracted)) {
		reflect_prob = schlick(cosine, ref_idx);
		//scattered = Ray(rec.p, refracted);
	}
	else {
		//scattered = Ray(rec.p, reflected);
		return false;
	}
	if ((rand() % (100) / (float)(100)) < reflect_prob) {
		scattered = Ray(rec.p, reflected);
	}
	else
	{
		scattered = Ray(rec.p, refracted);
	}
	return true;
}
