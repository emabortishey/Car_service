#include "Header.h"

class Car_dealership
{
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

	void add(initializer_list<Car> init_list)
	{
		for (auto buff : init_list)
		{
			cars.push_back(buff);
		}
	}

	void add(Car obj) { cars.push_back(obj); }

	void remove(initializer_list<Car> init_list)
	{
		for (Car buff : init_list)
		{
			cars.remove(buff);
		}
	}

	void remove(Car obj) { cars.remove(obj); }


};