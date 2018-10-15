#include "Lambertian.h"

Vec3 random_in_unit_Sphere() {
	/*����������½����н��ܹ���������������������һ���������ԭ�㣬����С��1��������������������������ͽ��㴦��λ��������Ӿ͵õ����㴦�����������ķ�������*/
	Vec3 p;
	do {
		p = 2.0*Vec3((rand() % (100) / (float)(100)),
			(rand() % (100) / (float)(100)),
			(rand() % (100) / (float)(100)))
			- Vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

bool Lambertian::scatter(const Ray& r_in, const Hit_record& rec, Vec3& attenuation, Ray& scattered) const {
	/*�������ʵ��Lambertian::scatter()�����������飺��ȡ������ķ�����ߣ���ȡ���ʵ�˥��ϵ���� */
	Vec3 target = rec.p + rec.normal + random_in_unit_Sphere();
	scattered = Ray(rec.p, target - rec.p);
	//attenuation = albedo;
	attenuation = rec.tex_ptr->get_color(rec);
	return true;
}