#ifndef RECTANGULARMAP_H
#define RECTANGULARMAP_H

#include "RayTracer/Mapping.h"
class RectangularMap : public Mapping {
public:
	RectangularMap() = default;
	RectangularMap(const RectangularMap& rm);
	RectangularMap& operator= (const RectangularMap& rhs);
	virtual RectangularMap* clone() const;
	void get_texel_coordinates(const Hit_record& rec, const int xres, const int yres, int& row, int& column) const;
	~RectangularMap() {}
};
#endif // !RECTANGULARMAP_H
