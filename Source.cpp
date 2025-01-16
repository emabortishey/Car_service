#include "Header.h"
#include "Car_dealership.h"

using namespace std;

enum menu { ADD_CAR = 1, DELETE_CAR, SHOW_CARS, SORT_BY, SEARCH_BY };

int main()
{
	setlocale(LC_ALL, "Russian");

	// �������� ������ ������ ����������
	Car_dealership test{ {"constructor_test", 2000, 1985, 750} };

	// �������� ��� 3 �������� � 
	// ������������� � ������� ������
	test.add({ {"addcheck", 3000,8,4}, {"somename2", 1500,6,6}, {"ilovecats", 1,4,3} });

	// ���������� ��� ������ �� 
	// ������ � ��� ����� ��������
	int user_choice = 0;
	// �������� ���������� ��� ��� ������
	// � �������� ��� ���������� ����������
	// ������������� ���� ����� �� ������� �����
	// � ������� ���� ���� ���� ����������
	int buff_p;
	// ���������� ������, ������� ������������
	// ��� ��������/����������
	string buff_string;
	// ��������� ���������� ������, ������� ����������
	// � ����� ��������/���������� (�� ������������ ���������
	// ���������� �� ������ ��������������� �����
	// ��������� ����� ����������� �������� ���������� � �����)
	Car buff_car;
	// ��������� ������ �������������� ��� ������
	// ������ ������ � ����������� ������ �� �����
	// ���������� ������������ �� ��������� ���������
	vector<Car> buff_car_vector;

	cout << "\n������� ����� � ����������� �� ������ ������:\n1. �������� ����\n2. ������� ����\n3. ������� ��� ����\n4. ����������� �� ��������\n5. ����� �� ��������\n";

	cin >> user_choice;
	
	while (user_choice != 0)
	{
		switch (user_choice)
		{

		// ���������� ����
		case ADD_CAR:
		{
			cout << "\n\n������� ����� �� �� ������ ��������? ";

			cin >> user_choice;

			// ���� � ������� ����������� �������� ������
			// ������ ��� ��� �������� � ����� ����������
			for (int i = 0; i < user_choice; i++)
			{
				// ������ �� ������� ������� ��������
				// ������ ��� � �������� �� � ������������
				cout << "\n\n������� ����� ����: ";

				cin >> buff_string;
				buff_car.set_brand(buff_string);

				cout << "\n������� ����: ";

				cin >> buff_p;
				buff_car.set_price(buff_p);

				cout << "\n������� ��� �������: ";

				cin >> buff_p;
				buff_car.set_year(buff_p);

				cout << "\n������� ����� ���������: ";

				cin >> buff_p;
				buff_car.set_volume(buff_p);

				// ����� ������ ���������� � ����� ����������
				// � ������� ���������� ����������� ��������� ������
				test.add(buff_car);
			}

			break;
		}
		case DELETE_CAR:
		{
			cout << "\n\n������� ����� �� �� ������ �������? ";

			cin >> user_choice;

			// �� �� ����� ��� � � �����������, �� �����
			// ���������� ��������� ������� ������ ���
			// ���������� ����� ��� �������� �������� � �����
			for (int i = 0; i < user_choice; i++)
			{
				cout << "\n\n������� ����� ����: ";

				cin >> buff_string;
				buff_car.set_brand(buff_string);

				cout << "\n������� ����: ";

				cin >> buff_p;
				buff_car.set_price(buff_p);

				cout << "\n������� ��� �������: ";

				cin >> buff_p;
				buff_car.set_year(buff_p);

				cout << "\n������� ����� ���������: ";

				cin >> buff_p;
				buff_car.set_volume(buff_p);

				test.remove(buff_car);
			}

			break;
		}

		// ����� ������ ������ ���� ����� ����������
		case SHOW_CARS:
		{
			test.show_all_cars();

			break;
		}

		// �������� � ����� ���������� �����, ��������� �������������
		// ������� � ����������� �� ����������� �������� 
		// �������� �������� ���������� � ������ ���������
		case SORT_BY:
		{
			cout << "\n�������� �������� ����������\n\n1. �����\n2. ����\n3. ��� �������\n4. ����� ���������";

			cin >> user_choice;

			test.sort_by_smth(user_choice);

			break;
		}
		// �� �� ����� ��� � ����������, ������ ��� 
		// ������ �� ������ ��������� ��������� � 
		// �������� �������� ����, ����� ������ ��������
		// ���������� ����� ���� ��������� �����������
		case SEARCH_BY:
		{
			cout << "\n�������� �������� ������:\n\n1. �����\n2. ����\n3. ��� �������\n4. ����� ���������";

			cin >> user_choice;

			switch (user_choice)
			{
			case BY_BRAND:
			{
				cout << "\n������� ������: ";

				cin >> buff_string;

				buff_car_vector = test.search_by_name(buff_string);
			}
			case BY_PRICE:
			{
				cout << "\n������� ����: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_price(buff_p);
			}
			case BY_YEAR:

			{
				cout << "\n������� ���: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_year(buff_p);
			}
			case BY_VOLUME:
			{
				cout << "\n������� ����� ���������: ";

				cin >> buff_p;

				buff_car_vector = test.search_by_volume(buff_p);

				break;
			}

			cout << "\n\n��������� �� �������� ����������:\n";
			for (auto buff : buff_car_vector)
			{
				buff.show_car();
			}
			}

		}
		}

		// ��������� ����� �����, ���� �� ����� ����� 0
		cout << "\n������� ����� � ����������� �� ������ ������:\n1. �������� ����\n2. ������� ����\n3. ������� ��� ����\n4. ����������� �� ��������\n5. ����� �� ��������\n";

		cin >> user_choice;

		// ������� ������� ��� ��������
		system("cls");
	}

	return 0;
}
