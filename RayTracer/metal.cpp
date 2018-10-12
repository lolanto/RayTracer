#include "Metal.h"
#include "Lambertian.h"

Vec3 reflect(const Vec3& v, const Vec3& n) {
	return v - 2 * dot(v, n)*n;
}

bool Metal::scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const {
	/*�������ʵ��Metal::scatter()�����������飺��ȡ���淴��ķ�����ߣ���ȡ���ϵ�˥��ϵ���� */
	Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
	scattered = Ray(rec.p, reflected + fuzz * random_in_unit_Sphere());
	attenuation = albedo;
	return (dot(scattered.direction(), rec.normal) > 0);
}