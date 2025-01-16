#include "Header.h"

using namespace std;

// класс машина
class Car
{
	string brand;
	int price;
	int year;
	int volume;

public:
	Car() = default;
	Car(string brand_P, int price_P, int year_P, int volume_P) : brand{ brand_P }, price{ price_P }, year{ year_P }, volume{ volume_P } { };

	// метод вывода всех критериев авто
	void show_car() { cout << "\n\nМарка авто: " << brand << "\nЦена: " << price << "\nГод выпуска: " << year << "\nОбъем двигателя: " << volume; }

	// перегрузка оператора бинарной проверки на равенство для корректной работа алгоритмов
	bool operator==(const Car& obj) const { return (brand == obj.brand && price == obj.price && year == obj.year, volume == obj.volume); }

	void set_brand(string brand_P) { brand = brand_P; }
	void set_price(int price_P) { price = price_P; }
	void set_year(int year_P) { year = year_P; }
	void set_volume(int volume_P) { volume = volume_P; }

	string get_brand() { return brand; }
	int get_price() { return price; }
	int get_year() { return year; }
	int get_volume() { return volume; }
};
