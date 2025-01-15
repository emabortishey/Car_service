#include "Header.h"
#include "Car.h"
#include "Functors.h"

using namespace std;

enum search_by { search_BY_BRAND = 1, search_BY_PRICE, search_BY_YEAR, search_BY_VOLUME };
enum sort_by { sort_BY_BRAND = 1, sort_BY_PRICE, sort_BY_YEAR, sort_BY_VOLUME };

class Car_dealership
{
	vector<Car> cars;
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
			cars.erase(find_if(cars.begin(), cars.end(), search_name(buff)));
		}
	}

	void remove(Car obj) { cars.erase(find_if(cars.begin(), cars.end(), search_name(obj))); }

	void sort_by_smth(int by_what = sort_BY_BRAND)
	{
		sort(cars.begin(), cars.end(), sort_name());
	}
};