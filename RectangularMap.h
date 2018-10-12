#ifndef RECTANGULARMAP_H
#define RECTANGULARMAP_H

#include "RayTracer/Mapping.h"
class RectangularMap : public Mapping {
public:
	RectangularMap() = default;
	void get_texel_coordinates(const Vec3& hit_point, const int xres, const int yres, int& row, int& column) const;
};
#endif // !RECTANGULARMAP_H
