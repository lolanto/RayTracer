#include "lambertian.h"

vec3 random_in_unit_sphere() {
	/*漫反射材质章节中有介绍过这个函数。这个函数产生一个“起点在原点，长度小于1，方向随机”的向量，该向量和交点处单位法向量相加就得到交点处反射光线随机的方向向量*/
	vec3 p;
	do {
		p = 2.0*vec3((rand() % (100) / (float)(100)),
			(rand() % (100) / (float)(100)),
			(rand() % (100) / (float)(100)))
			- vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
	/*这里具体实现lambertian::scatter()。做两件事情：获取漫反射的反射光线；获取材质的衰减系数。 */
	vec3 target = rec.p + rec.normal + random_in_unit_sphere();
	scattered = ray(rec.p, target - rec.p);
	attenuation = albedo;
	return true;
}