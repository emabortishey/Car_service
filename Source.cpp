#include "Header.h"
#include "Car_dealership.h"

using namespace std;

enum menu { ADD_CAR = 1, DELETE_CAR, SHOW_CARS, SORT_BY, SEARCH_BY };

int main()
{
	setlocale(LC_ALL, "Russian");

	Car_dealership test{ {"constructor_test", 2000, 1985, 750} };

	test.add({ {"addcheck", 3000,8,4}, {"somename2", 1500,6,6}, {"ilovecats", 1,4,3} });

	int user_choice = 0;
	int buff_p;
	string buff_string;
	Car buff_car;
	vector<Car> buff_car_vector;

	cout << "\nВведите число в зависимости от вашего выбора:\n1. Добавить авто\n2. Удалить авто\n3. Вывести все авто\n4. Сортировать по критерию\n5. Найти по критерию\n";

	cin >> user_choice;
	
	while (user_choice != 0)
	{
		switch (user_choice)
		{


		case ADD_CAR:
		{
			cout << "\n\nСколько машин вы бы хотели добавить? ";

			cin >> user_choice;

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

				test.add(buff_car);
			}

			break;
		}
		case DELETE_CAR:
		{
			cout << "\n\nСколько машин вы бы хотели удалить? ";

			cin >> user_choice;

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
		case SHOW_CARS:
		{
			test.show_all_cars();

			break;
		}
		case SORT_BY:
		{
			cout << "\nВыберите критерий сортировки\n\n1. Марка\n2. Цена\n3. Год выпуска\n4. Объем двигателя";

			cin >> user_choice;

			test.sort_by_smth(user_choice);

			break;
		}
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

				test.search_by_name(buff_string);
			}
			case BY_PRICE:
			{
				cout << "\nВведите цену: ";

				cin >> buff_p;

				test.search_by_price(buff_p);
			}
			case BY_YEAR:

			{
				cout << "\nВведите год: ";

				cin >> buff_p;

				test.search_by_year(buff_p);
			}
			case BY_VOLUME:
			{
				cout << "\nВведите объем двигателя: ";

				cin >> buff_p;

				test.search_by_volume(buff_p);

				break;
			}
			}

		}
		}

		cout << "\nВведите число в зависимости от вашего выбора:\n1. Добавить авто\n2. Удалить авто\n3. Вывести все авто\n4. Сортировать по критерию\n5. Найти по критерию\n";

		cin >> user_choice;
	}

	return 0;
}
