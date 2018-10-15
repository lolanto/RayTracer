#ifndef SPHERICALMAP_H
#define SPHERICALMAP_H

#include "RayTracer/Mapping.h"

class SphericalMap : public Mapping {
public:
	SphericalMap() = default;
	SphericalMap(const SphericalMap& sm);
	SphericalMap& operator= (const SphericalMap& rhs);
	virtual SphericalMap* clone() const;
	virtual void get_texel_coordinates(const Hit_record& rec, const int xres, const int yres, int& row, int& column) const;
	~SphericalMap() {}
};
#endif // !SPHERICALMAP_H

