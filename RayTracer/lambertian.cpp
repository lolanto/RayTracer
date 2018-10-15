#include "Lambertian.h"

Vec3 random_in_unit_Sphere() {
	/*漫反射材质章节中有介绍过这个函数。这个函数产生一个“起点在原点，长度小于1，方向随机”的向量，该向量和交点处单位法向量相加就得到交点处反射光线随机的方向向量*/
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
	/*这里具体实现Lambertian::scatter()。做两件事情：获取漫反射的反射光线；获取材质的衰减系数。 */
	Vec3 target = rec.p + rec.normal + random_in_unit_Sphere();
	scattered = Ray(rec.p, target - rec.p);
	//attenuation = albedo;
	attenuation = rec.tex_ptr->get_color(rec);
	return true;
}