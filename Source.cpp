#include "Header.h"
#include "Car_dealership.h"

using namespace std;

enum menu { ADD_CAR = 1, DELETE_CAR, SHOW_CARS, SORT_BY, SEARCH_BY };

int main()
{
	setlocale(LC_ALL, "Russian");

	// тестовый обьект класса автосалона
	Car_dealership test{ {"constructor_test", 2000, 1985, 750} };

	// добавляю ещё 3 элемента к 
	// существующему с помощью метода
	test.add({ {"addcheck", 3000,8,4}, {"somename2", 1500,6,6}, {"ilovecats", 1,4,3} });

	// переменная для работы со 
	// свичом и ещё парой моментов
	int user_choice = 0;
	// буферная переменная инт для работы
	// с консолью где невозможно повтороное
	// использование юзер чоиса по причине цикла
	// в который этот юзер чоис фигурирует
	int buff_p;
	// переменная стринг, которая используется
	// для удаления/добавления
	string buff_string;
	// буфферная переменная машины, которая передается
	// в метод удаления/добавления (не использовала созданную
	// перегрузку со списом инициализаторов чтобы
	// сократить число создаваемых буферных переменных в мейне)
	Car buff_car;
	// буфферный вектор использующийся при вызове
	// метода поиска и принимающий вектор со всеми
	// найденными автомобилями по заданному параметру
	vector<Car> buff_car_vector;

	cout << "\nВведите число в зависимости от вашего выбора:\n1. Добавить авто\n2. Удалить авто\n3. Вывести все авто\n4. Сортировать по критерию\n5. Найти по критерию\n";

	cin >> user_choice;
	
	while (user_choice != 0)
	{
		switch (user_choice)
		{

		// добавление авто
		case ADD_CAR:
		{
			cout << "\n\nСколько машин вы бы хотели добавить? ";

			cin >> user_choice;

			// цикл в котором заполняется буферный обьект
			// класса кар для передачи в метод добавления
			for (int i = 0; i < user_choice; i++)
			{
				// запрос по очереди каждого атрибута
				// класса кар и передача их в модификаторы
				cout << "\n\nВведите марку авто: ";

				cin >> buff_string;
				buff_car.set_brand(buff_string);

				cout << "\nВведите цену: ";

				cin >> buff_p;
				buff_car.set_price(buff_p);

				cout << "\nВведите год выпуска: ";

				cin >> buff_p;
				buff_car.set_year(buff_p);

				cout << "\nВведите объем двигателя: ";

				cin >> buff_p;
				buff_car.set_volume(buff_p);

				// вызов метода добавления в класс автосалона
				// в который передается заполненная перменная машины
				test.add(buff_car);
			}

			break;
		}
		case DELETE_CAR:
		{
			cout << "\n\nСколько машин вы бы хотели удалить? ";

			cin >> user_choice;

			// то же самое что и с добавлением, но после
			// заполнения буферного обьекта класса кар
			// происходит вызов уже удаления обьектов в цикле
			for (int i = 0; i < user_choice; i++)
			{
				cout << "\n\nВведите марку авто: ";

				cin >> buff_string;
				buff_car.set_brand(buff_string);

				cout << "\nВведите цену: ";

				cin >> buff_p;
				buff_car.set_price(buff_p);

				cout << "\nВведите год выпуска: ";

				cin >> buff_p;
				buff_car.set_year(buff_p);

				cout << "\nВведите объем двигателя: ";

				cin >> buff_p;
				buff_car.set_volume(buff_p);

				test.remove(buff_car);
			}

			break;
		}

		// вызов метода вывода всех машин автосалона
		case SHOW_CARS:
		{
			test.show_all_cars();

			break;
		}

		// передача в метод сортировки числа, введённого пользователем
		// который в зависимости от переданного значения 
		// вызывает алгоритм сортировки с нужным функтором
		case SORT_BY:
		{
			cout << "\nВыберите критерий сортировки\n\n1. Марка\n2. Цена\n3. Год выпуска\n4. Объем двигателя";

			cin >> user_choice;

			test.sort_by_smth(user_choice);

			break;
		}
		// то же самое что и сортировка, однако тут 
		// вызовы по разным критериям разделены и 
		// добавлен вложеный свич, после работы которого
		// происходит вывод всех найденных автомобилей
		case SEARCH_BY:
		{
			cout << "\nВыберите критерий поиска:\n\n1. Марка\n2. Цена\n3. Год выпуска\n4. Объем двигателя";

			cin >> user_choice;

			switch (user_choice)
			{
			case BY_BRAND:
			{
				cout << "\nВведите строку: ";

				cin >> buff_string;

				buff_car_vector = test.search_by_name(buff_string);
			}
			case BY_PRICE:
			{
				cout << "\nВведите цену: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_price(buff_p);
			}
			case BY_YEAR:

			{
				cout << "\nВведите год: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_year(buff_p);
			}
			case BY_VOLUME:
			{
				cout << "\nВведите объем двигателя: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_volume(buff_p);

				break;
			}

			cout << "\n\nНайденные по критерию автомобили:\n";
			for (auto buff : buff_car_vector)
			{
				buff.show_car();
			}
			}

		}
		}

		// цикличный вызов свича, пока не будет введён 0
		cout << "\nВведите число в зависимости от вашего выбора:\n1. Добавить авто\n2. Удалить авто\n3. Вывести все авто\n4. Сортировать по критерию\n5. Найти по критерию\n";

		cin >> user_choice;

		// очистка консоли для удобства
		system("cls");
	}

	return 0;
}
