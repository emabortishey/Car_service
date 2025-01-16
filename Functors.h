#pragma once
#include "Header.h"

using namespace std;

// заголовочный файл со всеми функторами 
// которые используются в методах класса car realershit
class search_name
{
	// т.к. копи иф, который я использовала
	// для метода поиска, принимает только 
	// унарные функторы, я добавила атрибут
	string obj;
public:
	search_name() = delete;
	search_name(string obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.get_brand() == obj; }
};

class search_price
{
	int obj;
public:
	search_price() = delete;
	search_price(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.get_price() == obj; }
};

class search_year
{
	int obj;
public:
	search_year() = delete;
	search_year(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.get_year() == obj; }
};

class search_volume
{
	int obj;
public:
	search_volume() = delete;
	search_volume(int obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1) { return obj1.get_volume() == obj; }
};

// функтор для поиска машины, подходящей
// по всем параметрам, созданный для метода удаления
// т.к. в классе веткора нет метода ремув,
// я использовала метод эрейс, в который передавала
// полученый с помощью алгоритма файнд иф итератор
// а в алгоритм файнд иф я передавала этот функтор
class search_car
{
	Car obj;
public:
	search_car() = default;
	search_car(Car obj_P) : obj{ obj_P } { };

	bool operator()(Car& obj1, Car& obj2) { return obj1.get_brand() == obj2.get_brand() && obj1.get_price() == obj2.get_price() && obj1.get_year() == obj2.get_year() && obj1.get_volume() == obj2.get_volume(); }
	bool operator()(Car& obj1) { return obj1.get_brand() == obj.get_brand() && obj1.get_price() == obj.get_price() && obj1.get_year() == obj.get_year() && obj1.get_volume() == obj.get_volume(); }
};


class sort_name
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.get_brand() > obj2.get_brand(); }
};

class sort_price
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.get_price() > obj2.get_price(); }
};

class sort_year
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.get_year() > obj2.get_year(); }
};

class sort_volume
{
public:
	bool operator()(Car& obj1, Car& obj2) { return obj1.get_volume() > obj2.get_volume(); }
};