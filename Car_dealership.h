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
	// для каждого обьекта вектора 
	void show_all_cars();

	// не помню зачем добавляла перегрузку
	// с параметром списка инициализаторов
	// но решила оставить на всякий случай
	void add(initializer_list<Car> init_list);

	// пушбек элемента в вектор
	void add(Car obj) { cars.push_back(obj); }

	void remove(initializer_list<Car> init_list);

	// то же самое что и с прошлой перегрузкй, 
	// но еденичный вызов метода вектора
	void remove(Car obj) { cars.erase(find_if(cars.begin(), cars.end(), search_car(obj))); }

	// метод сортировки, обьединяющий все4 критерия
	// по которым будет выполняться сортировка
	void sort_by_smth(int by_what);

	// поиск по имени (не обьеденила эти методы
	// т.к. у 1 атрибута отличный от остальных тип)

	// каждый метод создает буферный вектор со всеми
	// найденными машинами и возвращает его, для
	// дальнейшей рабта с ним пользователя
	vector<Car> search_by_name(string name_P);

	vector<Car> search_by_price(int price_P);

	vector<Car> search_by_year(int year_P);

	vector<Car> search_by_volume(int volume_P);
};