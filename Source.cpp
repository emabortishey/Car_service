#include "Header.h"
#include "Car_dealership.h"

using namespace std;

enum menu { ADD_CAR = 1, DELETE_CAR, SHOW_CARS, SORT_BY, SEARCH_BY };
enum under_menu1 { BY_BRAND = 1, BY_PRICE, BY_YEAR, BY_VOLUME };
enum under_menu2 { ADD_SINGLE = 1, ADD_LIST };
enum under_menu3 { DELETE_SINGLE = 1, DELETE_LIST };

int main()
{
	setlocale(LC_ALL, "Russian");

	Car_dealership test{ {"constructor_test", 2000, 1985, 750} };

	test.add({ {"addcheck", 3000,8,4}, {"somename2", 1500,6,6}, {"ilovecats", 1,4,3} });

	test.show_all_cars();

	//test.remove({ "MEOW", 2, 3, 4 });

	cout << "\n\nSECOND:\n\n";

	test.sort_by_smth(sort_BY_YEAR);

	test.show_all_cars();

	cout << "\n\nSECOND2:\n\n";

	for (auto buff : test.search_by_name("meow"))
	{
		buff.show_car();
	}

	int user_choice = 0;
	string buff_string;

	switch (user_choice)
	{
		cout << "\n������� ����� � ����������� �� ������ ������:\n1. �������� ����\n2. ������� ����\n3. ������� ��� ����\n4. ����������� �� ��������\n5. ����� �� ��������\n";

		cin >> user_choice;

	case ADD_CAR:
	{
		cout << "\n\n�� ������� ������� ��������� ������� (1) ��� ������ ��������� (2)? ";

		cin >> user_choice;

		switch (user_choice)
		{
		case ADD_SINGLE:
		{
			
		}
		case ADD_LIST:
		{
			cout << "\n\n������� ����� �� �� ������ ��������? ";

			cin >> user_choice;

			for (int i = 0; i < user_choice; i++)
			{

			}
		}
		}
	}
	case DELETE_CAR:
	{

	}
	case SHOW_CARS:
	{

	}
	case SORT_BY:
	{

	}
	case SEARCH_BY:
	{

	}
	}

	return 0;
}
