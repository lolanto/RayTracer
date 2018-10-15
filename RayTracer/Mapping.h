#ifndef MAPPING_H
#define MAPPING_H

#define _USE_MATH_DEFINES
#include <cmath>
#include "Vec3.h"
#include "Hitable.h"

const double 	PI = 3.1415926535897932384;
const double 	TWO_PI = 6.2831853071795864769;
const double 	PI_ON_180 = 0.0174532925199432957;
const double 	invPI = 0.3183098861837906715;
const double 	invTWO_PI = 0.1591549430918953358;

class Mapping {
public:
	Mapping() = default;
	Mapping(const Mapping& m);
	Mapping& operator=(const Mapping& rhs);
	virtual Mapping* clone() const = 0;
	virtual ~Mapping() {}
	virtual void get_texel_coordinates(const Hit_record& rec, const int xres, const int yres, int& row, int& column) const = 0;
};
#endif // !MAPPING_H
