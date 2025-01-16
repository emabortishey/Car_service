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
	// �� �������������� � ��������������� � 
	// ������� 1 �� ������� ����������������
	Car_dealership(initializer_list<Car> init_list) : cars{ init_list } { };

	// ��������� ����� ������ ������ 
	// ��� ������� ������� ������� 
	void show_all_cars();

	// �� ����� ����� ��������� ����������
	// � ���������� ������ ���������������
	// �� ������ �������� �� ������ ������
	void add(initializer_list<Car> init_list);

	// ������ �������� � ������
	void add(Car obj) { cars.push_back(obj); }

	void remove(initializer_list<Car> init_list);

	// �� �� ����� ��� � � ������� ����������, 
	// �� ��������� ����� ������ �������
	void remove(Car obj) { cars.erase(find_if(cars.begin(), cars.end(), search_car(obj))); }

	// ����� ����������, ������������ ���4 ��������
	// �� ������� ����� ����������� ����������
	void sort_by_smth(int by_what);

	// ����� �� ����� (�� ���������� ��� ������
	// �.�. � 1 �������� �������� �� ��������� ���)

	// ������ ����� ������� �������� ������ �� �����
	// ���������� �������� � ���������� ���, ���
	// ���������� ����� � ��� ������������
	vector<Car> search_by_name(string name_P);

	vector<Car> search_by_price(int price_P);

	vector<Car> search_by_year(int year_P);

	vector<Car> search_by_volume(int volume_P);
};