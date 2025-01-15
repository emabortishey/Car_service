#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Car_dealership
{
	class Car
	{
	public:
		string brand;
		int price;
		int year;
		int volume;

		Car(string brand_P, int price_P, int year_P, int volume_P) : brand{ brand_P }, price{ price_P }, year{ year_P }, volume{ volume_P } { };
	};

	friend Car;

	list<Car> Cars; 

public:
	Car_dealership() = default;
	Car_dealership(initializer_list<Car> init_list) : Cars{ init_list } { };

};