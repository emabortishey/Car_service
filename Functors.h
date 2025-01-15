#pragma once
#include "Header.h"

using namespace std;

class search_name
{
	string obj;
public:
	search_name() = default;
	search_name(string obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.brand == obj; }
};

class search_price
{
	int obj;
public:
	search_price() = default;
	search_price(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.price == obj; }
};

class search_year
{
	int obj;
public:
	search_year() = default;
	search_year(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.year == obj; }
};

class search_volume
{
	int obj;
public:
	search_volume() = default;
	search_volume(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.volume == obj; }
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
	bool operator()(Car& obj1, Car& obj2) { return obj1.brand > obj2.brand; }
};

class sort_price
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.price > obj2.price; }
};

class sort_year
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.year > obj2.year; }
};

class sort_volume
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.volume > obj2.volume; }
};