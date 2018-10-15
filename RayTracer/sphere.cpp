#include "Sphere.h"

std::vector<Vec3> Sphere::getAttribute() const {
	std::vector<Vec3> temp;
	temp.push_back(center);
	return temp;
}

bool Sphere::hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const {
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0*dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - 4 * a*c;
	if (discriminant > 0.0) {
		float temp = (-b - sqrt(discriminant)) / (2.0*a);
		if (temp<t_max&&temp>t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.obj = this;
			rec.mat_ptr = ma;
			rec.tex_ptr = tex;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / (2.0*a);
		if (temp<t_max&&temp>t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.obj = this;
			rec.mat_ptr = ma;
			rec.tex_ptr = tex;
			return true;
		}
	}
	return false;
}