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

		void show_car() { cout << "\nМарка авто: " << brand << "\nЦена: " << price << "\nГод выпуска: " << year << "\nОбъем двигателя: " << volume; }
	};

	friend Car;

	list<Car> cars; 

public:
	Car_dealership() = default;
	Car_dealership(initializer_list<Car> init_list) : cars{ init_list } { };

	void show_all_cars()
	{
		for (auto buff : cars)
		{
			buff.show_car();
			cout << '\n';
		}
	}



};