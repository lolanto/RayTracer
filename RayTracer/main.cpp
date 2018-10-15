#include <iostream>  
#include <fstream>  
#include "Sphere.h"
#include "..\Rectangle.h"
#include "Hitable_list.h"
#include "Camera.h"
#include "Lambertian.h"
#include "Metal.h"
#include "..\Dielectric.h"
#include "Color.h"
#include "Image.h"
#include "..\SphericalMap.h"
#include "..\RectangularMap.h"
#include <cfloat>
#include <limits>
#include <random>
using namespace std;


Color3 color(const Ray& r, Hitable* world, int depth) {
	Hit_record rec;
	if (world->hit(r, 0.001, (numeric_limits<float>::max)(), rec)) {
		Ray scattered;
		Color3 attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation*color(scattered, world, depth + 1);
		}
		//if (rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
		//	return attenuation;
		//}
		else
		{
			return Color3(0, 0, 0);
		}
	}
	else
	{
		Vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 - t)*Color3(1.0, 1.0, 1.0) + t*Color3(0.5, 0.7, 1.0);
	}
}

/*
Hitable *random_scene() {
	int n = 500;
	Hitable **list = new Hitable *[n + 1];
	list[0] = new Sphere(Vec3(0, -1000, 0), 1000, new Lambertian(Vec3(0.5, 0.5, 0.5)));
	int i = 1;
	for (int a = -11; a < 11; a++) {
		for (int b = -11; b < 11; b++) {
			float choose_mat = (rand() % (100) / (float)(100));
			Vec3 center(a + 0.9*(rand() % (100) / (float)(100)), 0.2,
				b + 0.9*(rand() % (100) / (float)(100)));
			if ((center - Vec3(4, 0.2, 0)).length() > 0.9) {
				if (choose_mat < 0.8) {     
					list[i++] = new Sphere(center, 0.2,
						new Lambertian(Vec3(
						(rand() % (100) / (float)(100))*(rand() % (100) / (float)(100)),
							(rand() % (100) / (float)(100))*(rand() % (100) / (float)(100)),
							(rand() % (100) / (float)(100))*(rand() % (100) / (float)(100)))));
				}
				else if (choose_mat < 0.95) {
					list[i++] = new Sphere(center, 0.2,
						new Metal(Vec3(0.5*(1 + (rand() % (100) / (float)(100))),
							0.5*(1 + (rand() % (100) / (float)(100))),
							0.5*(1 + (rand() % (100) / (float)(100)))),
							0.5*(1 + (rand() % (100) / (float)(100)))));
				}
				else {
					list[i++] = new Sphere(center, 0.2, new Dielectric(1.5));
				}
			}
		}
	}

	list[i++] = new Sphere(Vec3(0, 1, 0), 1.0, new Dielectric(1.5));
	list[i++] = new Sphere(Vec3(-4, 1, 0), 1.0, new Lambertian(Vec3(0.4, 0.2, 0.1)));
	list[i++] = new Sphere(Vec3(4, 1, 0), 1.0, new Metal(Vec3(0.7, 0.6, 0.5), 0.0));

	return new Hitable_list(list, i);
}
*/


int main()
{
	int nx = 200;
	int ny = 100;
	int ns = 100;
	uniform_real_distribution<float> randomFloats(0.0, 1.0);
	default_random_engine generator;

	ofstream outfile(".\\result\\RecTexture.ppm");
	if (!outfile.is_open()) {
		cout << (outfile.rdstate() & std::ofstream::failbit) << endl;
		system("pause");
		return 0;
	}
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	//std::cout << "P3\n" << nx << " " << ny << "\n255\n";

	//Hitable* list[4];
	//list[0] = new Sphere(Vec3(0, 0, -1), 0.5, new Lambertian(Vec3(0.8, 0.3, 0.3)));
	//list[1] = new Sphere(Vec3(0, -100.5, -1), 100, new Lambertian(Vec3(0.8, 0.8, 0.0)));
	//list[2] = new Sphere(Vec3(1, 0, -1), 0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0.0));
	//list[3] = new Sphere(Vec3(-1, 0, -1), 0.5, new Dielectric(1.5));
	//Hitable* world = new Hitable_list(list, 4);
	//Hitable* world = random_scene();
	Hitable* list[1];
	//list[0] = new Rectangle(Vec3(0, 0, 0), Vec3(2, 0, 0), Vec3(0, 2, 0), Vec3(0, 0, -1), new Lambertian(Vec3(0.8, 0.3, 0.3)));
	Image* image_ptr = new Image;
	image_ptr->read_ppm_file(".\\Textures\\color.ppm");
	//SphericalMap* map_ptr = new SphericalMap;
	RectangularMap* map_ptr = new RectangularMap;
	ImageTexture* texture_ptr = new ImageTexture;
	texture_ptr->set_image(image_ptr);
	texture_ptr->set_mapping(map_ptr);
	//list[0] = new Sphere(Vec3(0, 1, -1), 0.5, new Lambertian(Vec3(0.8, 0.3, 0.3)), texture_ptr);
	list[0] = new Rectangle(Vec3(0, 0, 0), Vec3(2, 0, 0), Vec3(0, 2, 0), Vec3(0, 0, -1), new Lambertian(Vec3(0.8, 0.3, 0.3)), texture_ptr);
	Hitable* world = new Hitable_list(list, 1);
	//Camera cam(Vec3(-2, 2, 1), Vec3(0, -1, 0), Vec3(0, 1, 0), 90, float(nx) / float(ny));
	//Camera cam(Vec3(13, 2, 3), Vec3(0, 0, 0), Vec3(0, 1, 0), 20, float(nx) / float(ny));
	Camera cam(Vec3(1, 1, 1), Vec3(1, 1, -1), Vec3(0, 1, 0), 60, float(nx) / float(ny));

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			Vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float randFloat = randomFloats(generator);
				float u = float(i + randFloat) / float(nx);
				float v = float(j + randFloat) / float(ny);
				Ray r = cam.get_Ray(u, v);
				col += color(r, world, 0);
			}
			col /= (float)ns;
			col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			outfile << ir << " " << ig << " " << ib << "\n";
			//std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	outfile.close();
}