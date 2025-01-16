#include "Header.h"
#include "Car.h"
#include "Functors.h"

using namespace std;

enum sort_by { BY_BRAND = 1, BY_PRICE, BY_YEAR, BY_VOLUME };

class Car_dealership
{
	vector<Car> cars;
public:
	Car_dealership() = default;
	// не заморачивалась с конуструкторами и 
	// сделала 1 со списком инициалимзаторов
	Car_dealership(initializer_list<Car> init_list) : cars{ init_list } { };

	// цикличный вызов метода показа 
	// дл€ каждого обьекта вектора 
	void show_all_cars()
	{
		for (auto buff : cars)
		{
			buff.show_car();
			cout << '\n';
		}
	}

	// не помню зачем добавл€ла перегрузку
	// с параметром списка инициализаторов
	// но решила оставить на вс€кий случай
	void add(initializer_list<Car> init_list)
	{
		// цикличный пушбек элементов списка инициализаторов
		for (auto buff : init_list)
		{
			cars.push_back(buff);
		}
	}

	// пушбек элемента в вектор
	void add(Car obj) { cars.push_back(obj); }

	void remove(initializer_list<Car> init_list)
	{
		// цикл по списку инициализаторов
		for (Car buff : init_list)
		{
			// т.к. в векторе нельз€ удалить определенный
			// элемент, € использую метод эрейс, который
			// принимает итератор на элемент, дл€ получени€
			// которого € использую алгоритм файнд иф, в который
			// передаю унарный функтор поиска подход€щей машины
			cars.erase(find_if(cars.begin(), cars.end(), search_car(buff)));
		}
	}

	// то же самое что и с прошлой перегрузкй, 
	// но еденичный вызов метода вектора
	void remove(Car obj) { cars.erase(find_if(cars.begin(), cars.end(), search_car(obj))); }

	// метод сортировки, обьедин€ющий все4 критери€
	// по которым будет выполн€тьс€ сортировка
	void sort_by_smth(int by_what)
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

	// поиск по имени (не обьеденила эти методы
	// т.к. у 1 атрибута отличный от остальных тип)

	// каждый метод создает буферный вектор со всеми
	// найденными машинами и возвращает его, дл€
	// дальнейшей рабта с ним пользовател€
	vector<Car> search_by_name(string name_P)
	{
		vector<Car> found_cars(cars.size());
		
		// используетс€ алгоритм копи иф, принимающий унарный функетр
		copy_if(cars.begin(), cars.end(), found_cars.begin(), search_name(name_P)); 	
			
		return found_cars;
	}

	vector<Car> search_by_price(int price_P)
	{
		vector<Car> found_cars(cars.size());

		copy_if(cars.begin(), cars.end(), found_cars.begin(), search_price(price_P));

		return found_cars;
	}

	vector<Car> search_by_year(int year_P)
	{
		vector<Car> found_cars(cars.size());

		copy_if(cars.begin(), cars.end(), found_cars.begin(), search_year(year_P));

		return found_cars;
	}

	vector<Car> search_by_volume(int volume_P)
	{
		vector<Car> found_cars(cars.size());

		copy_if(cars.begin(), cars.end(), found_cars.begin(), search_volume(volume_P));

		return found_cars;
	}
};