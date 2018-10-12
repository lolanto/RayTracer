#ifndef SPHERE_H
#define SPHERE_H
#include "Hitable.h"
#include "Material.h"

class Sphere :public Hitable {
public:
	Sphere() {}
	Sphere(Vec3 cen, float r, Material *m):center(cen),radius(r),ma(m){}
	bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const;
	Vec3 center;
	float radius;
	Material *ma;
};

#endif // !SPHERE_H

