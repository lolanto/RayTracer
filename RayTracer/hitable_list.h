#ifndef HITABLELIST_H
#define HITABLELIST_H
#include "Hitable.h"

class Hitable_list :public Hitable {
public:
	Hitable_list(){}
	Hitable_list(Hitable **l, int n) {
		list = l;
		list_size = n;
	}
	virtual bool hit(const Ray& r, float t_min, float t_max, Hit_record& rec)const;

	Hitable **list;
	int	list_size;

};
#endif // !HITABLELIST_H

