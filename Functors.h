#pragma once
#include "Header.h"

using namespace std;

class search_name
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.brand == obj2.brand; }
};

class search_price
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.price == obj2.price; }
};

class search_year
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.year == obj2.year; }
};

class search_volume
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.volume == obj2.volume; }
};

class search_car
{
	Car obj;
public:
	search_car() = default;
	search_car(Car obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1, Car& obj2) { return obj1.brand == obj2.brand && obj1.price == obj2.price && obj1.year == obj2.year && obj1.volume == obj2.volume; }
	bool operator()(Car& obj1) { return obj1.brand == obj.brand && obj1.price == obj.price && obj1.year == obj.year && obj1.volume == obj.volume; }
};


class sort_name
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.brand < obj2.brand; }
};

class sort_price
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.price < obj2.price; }
};

class sort_year
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.year < obj2.year; }
};

class sort_volume
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.volume < obj2.volume; }
};