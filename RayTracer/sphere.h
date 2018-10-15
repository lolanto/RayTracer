#ifndef SPHERE_H
#define SPHERE_H
#include "Hitable.h"
#include "Material.h"
#include "..\ImageTexture.h"

class Sphere :public Hitable {
public:
	Sphere() {}
	Sphere(Vec3 cen, float r, Material *m, ImageTexture* t):center(cen),radius(r),ma(m), tex(t) {}
	virtual bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const;
	virtual std::vector<Vec3> getAttribute() const;
	Vec3 center;
	float radius;
	Material* ma;
	ImageTexture* tex;
};

#endif // !SPHERE_H

