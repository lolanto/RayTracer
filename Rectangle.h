#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "RayTracer/Hitable.h"
#include "RayTracer/Material.h"
#include "ImageTexture.h"

class Rectangle : public Hitable {
public:
	Rectangle() = default;
	Rectangle(const Vec3& _p0, const Vec3& _a, const Vec3& _b, const Vec3& n, Material* m, ImageTexture* t);
	virtual bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const;
	virtual std::vector<Vec3> getAttribute() const;
	virtual ~Rectangle() {}
private:
	Vec3 p0;                    //corner point
	Vec3 a;                     //side
	Vec3 b;                     //side
	float a_len_square;          //square of length of side a
	float b_len_square;          //square of length of side b
	Vec3 normal;
	Material* ma;
	ImageTexture* tex;

	static const double kEpsilon;  
};
#endif // !RECTANGLE_H

