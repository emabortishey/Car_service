#pragma once
#include "Header.h"

class search_name
{
public:
	bool operator()(string name1, string name2) { return name1 == name2; }
};

class search_price
{
public:
	bool operator()(int price1, int price2) { return price1 == price2; }
};

class search_year
{
public:
	bool operator()(int year1, int year2) { return year1 == year2; }
};

class search_volume
{
public:
	bool operator()(int volume1, int volume2) { return volume1 == volume2; }
};