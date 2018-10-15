#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#define PI 3.14159265358979323846
class Camera{
public:
	Camera(Vec3 vpos, Vec3 lookat, Vec3 vup, float vfov, float aspect) { // vfov is top to bottom in degrees
		Vec3 u, v, w;
		float theta = vfov * PI / 180;
		float half_height = tan(theta / 2);
		float half_width = aspect * half_height;
		origin = vpos;
		w = unit_vector(vpos - lookat);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);
		lower_left_corner = origin - half_width * u - half_height * v - w;
		horizontal = 2 * half_width*u;
		vertical = 2 * half_height*v;
	}

	Ray get_Ray(float s, float t) { return Ray(origin, lower_left_corner + s * horizontal + t * vertical - origin); }	
	
	Vec3 lower_left_corner;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 origin;
};



#endif // CAMERA_H

