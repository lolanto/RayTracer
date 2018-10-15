#include "RectangularMap.h"

RectangularMap::RectangularMap(const RectangularMap& rm) {}

RectangularMap& RectangularMap::operator= (const RectangularMap& rhs){
	if (this == &rhs)
		return *this;
	return *this;
}

RectangularMap* RectangularMap::clone() const {
	return (new RectangularMap(*this));
}

void RectangularMap::get_texel_coordinates(const Hit_record& rec, const int xres, const int yres, int& row, int& column) const {
	std::vector<Vec3> attribute = rec.obj->getAttribute();
	Vec3 p = rec.p - attribute[0];
	float cosa = dot(attribute[1], p) / (attribute[1].length() * p.length());
	float sina = sqrt(1 - cosa * cosa);
	float u = (p.length() * cosa) / attribute[1].length();
	float v = (p.length() * sina) / attribute[2].length();

	column = (int)((xres - 1) * u);
	row = (int)((yres - 1) * v);
}