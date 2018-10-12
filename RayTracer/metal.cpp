#include "Metal.h"
#include "Lambertian.h"

Vec3 reflect(const Vec3& v, const Vec3& n) {
	return v - 2 * dot(v, n)*n;
}

bool Metal::scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const {
	/*这里具体实现Metal::scatter()。做两件事情：获取镜面反射的反射光线；获取材料的衰减系数。 */
	Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
	scattered = Ray(rec.p, reflected + fuzz * random_in_unit_Sphere());
	attenuation = albedo;
	return (dot(scattered.direction(), rec.normal) > 0);
}