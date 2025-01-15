#include "Header.h"

class Car
{
public:
	string brand;
	int price;
	int year;
	int volume;

	Car(string brand_P, int price_P, int year_P, int volume_P) : brand{ brand_P }, price{ price_P }, year{ year_P }, volume{ volume_P } { };

	void show_car() { cout << "\nМарка авто: " << brand << "\nЦена: " << price << "\nГод выпуска: " << year << "\nОбъем двигателя: " << volume; }


	bool operator==(const Car& obj) const { return (brand == obj.brand && price == obj.price && year == obj.year, volume == obj.volume); }
};
