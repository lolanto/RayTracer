#ifndef MAPPING_H
#define MAPPING_H
#include "Vec3.h"
class Mapping {
	Mapping() = default;
	//Mapping(const Mapping& m);
	//Mapping& operator=(const Mapping& rhs);
	//virtual Mapping* clone() const = 0;
	virtual ~Mapping() {}
	virtual void get_texel_coordinates(const Vec3& hit_point, const int xres, const int yres, int& row, int& column) const = 0;
};
#endif // !MAPPING_H
