#include "Rectangle.h"

const double Rectangle::kEpsilon = 0.001;

Rectangle::Rectangle(const Vec3& _p0, const Vec3& _a, const Vec3& _b, const Vec3& n, Material* m, ImageTexture* t) 
	:p0(_p0),
	a(_a),
	b(_b),
	a_len_square(_a.squared_length()),
	b_len_square(_b.squared_length()),
	normal(n),
	ma(m),
	tex(t)
{
	normal.make_unit_vector();
}

std::vector<Vec3> Rectangle::getAttribute() const {
	std::vector<Vec3> temp;
	temp.push_back(p0);
	temp.push_back(a);
	temp.push_back(b);
	
	return temp;
}

bool Rectangle::hit(const Ray& ray, float t_min, float t_max, Hit_record& rec) const {
	float temp = dot(p0 - ray.origin(), normal) / dot(ray.direction(), normal);

	if (temp < t_max && temp > t_min) {
		Vec3 p = ray.point_at_parameter(temp);
		Vec3 d = p - p0;

		float ddota = dot(d, a);
		if (ddota < 0.0 || ddota > a_len_square)
			return false;

		float ddotb = dot(d, b);
		if (ddotb < 0.0 || ddotb > b_len_square)
			return false;

		rec.t = temp;
		rec.p = ray.point_at_parameter(rec.t);
		rec.normal = normal;
		rec.obj = this;
		rec.mat_ptr = ma;
		rec.tex_ptr = tex;
		return true;
	}
	else {
		return false;
	}
}