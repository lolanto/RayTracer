#include "Hitable_list.h"

bool Hitable_list::hit(const Ray& r, float t_min, float t_max, Hit_record& rec) const {
	Hit_record temp_record;
	bool hit_anything = false;
	double closest_so_far = t_max;
	for (int i = 0; i < list_size; i++) {
		if (list[i]->hit(r, t_min, closest_so_far, temp_record)) {
			hit_anything = true;
			closest_so_far = temp_record.t;
			rec = temp_record;
		}
	}
	return hit_anything;
}