#include "metal.h"

vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2 * dot(v, n)*n;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
	/*这里具体实现metal::scatter()。做两件事情：获取镜面反射的反射光线；获取材料的衰减系数。 */
	vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
	scattered = ray(rec.p, reflected);
	attenuation = albedo;
	return (dot(scattered.direction(), rec.normal) > 0);
}