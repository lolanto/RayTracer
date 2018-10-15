#include "SphericalMap.h"

SphericalMap::SphericalMap(const SphericalMap& sm) {}

SphericalMap& SphericalMap::operator= (const SphericalMap& rhs) {
	if (this == &rhs)
		return (*this);

	return (*this);
}

SphericalMap* SphericalMap::clone() const {
	return (new SphericalMap(*this));
}

void SphericalMap::get_texel_coordinates(const Hit_record& rec, const int xres, const int yres, int& row, int& column) const {
	/*
	float theta = acos(hit_point.y());
	float phi = atan2(hit_point.x(), hit_point.z());
	if (phi < 0.0)
		phi += TWO_PI;

	float u = phi * invTWO_PI;
	float v = 1.0 - theta * invPI;
	*/
	Vec3 pole = Vec3(0, 1, 0);
	Vec3 equator = Vec3(0, 0, 1);
	float u, v;
	float phi = acos(-dot(rec.normal, pole));
	v = phi / M_PI;
	float theta = acos((dot(equator, rec.normal)) / (sin(phi) + 0.001)) / (2 * M_PI);
	if (dot(cross(pole, equator), rec.normal) > 0) {
		u = theta;
	}
	else {
		u = 1 - theta;
	}

	//std::cout << u << " " << v << std::endl;

	column = (int)((xres - 1) * u);   	
	row = (int)((yres - 1) * v);    	
}