#include "Car_dealership.h"

void Car_dealership::show_all_cars()
{
	for (auto buff : cars)
	{
		buff.show_car();
		cout << '\n';
	}
}

void Car_dealership::add(initializer_list<Car> init_list)
{
	// ��������� ������ ��������� ������ ���������������
	for (auto buff : init_list)
	{
		cars.push_back(buff);
	}
}

void Car_dealership::remove(initializer_list<Car> init_list)
{
	// ���� �� ������ ���������������
	for (Car buff : init_list)
	{
		// �.�. � ������� ������ ������� ������������
		// �������, � ��������� ����� �����, �������
		// ��������� �������� �� �������, ��� ���������
		// �������� � ��������� �������� ����� ��, � �������
		// ������� ������� ������� ������ ���������� ������
		cars.erase(find_if(cars.begin(), cars.end(), search_car(buff)));
	}
}

void Car_dealership::sort_by_smth(int by_what)
{
	switch (by_what)
	{
	case BY_BRAND:
	{
		sort(cars.begin(), cars.end(), sort_name());

		break;
	}
	case BY_PRICE:
	{
		sort(cars.begin(), cars.end(), sort_price());

		break;
	}
	case BY_YEAR:
	{
		sort(cars.begin(), cars.end(), sort_year());

		break;
	}
	case BY_VOLUME:
	{
		sort(cars.begin(), cars.end(), sort_volume());

		break;
	}
	}
}

vector<Car> Car_dealership::search_by_name(string name_P)
{
	vector<Car> found_cars(cars.size());

	// ������������ �������� ���� ��, ����������� ������� �������
	copy_if(cars.begin(), cars.end(), found_cars.begin(), search_name(name_P));

	return found_cars;
}

vector<Car> Car_dealership::search_by_price(int price_P)
{
	vector<Car> found_cars(cars.size());

	copy_if(cars.begin(), cars.end(), found_cars.begin(), search_price(price_P));

	return found_cars;
}

vector<Car> Car_dealership::search_by_year(int year_P)
{
	vector<Car> found_cars(cars.size());

	copy_if(cars.begin(), cars.end(), found_cars.begin(), search_year(year_P));

	return found_cars;
}

vector<Car> Car_dealership::search_by_volume(int volume_P)
{
	vector<Car> found_cars(cars.size());

	copy_if(cars.begin(), cars.end(), found_cars.begin(), search_volume(volume_P));

	return found_cars;
}