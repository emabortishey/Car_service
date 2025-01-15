#include "Car_dealership.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Car_dealership test{ {"carname", 2000, 1985, 750} };

	test.add({ {"MEOW", 2,3,4}, {"BARK", 4,5,6}, {"MEOW", 6,7,8} });

	test.show_all_cars();

	test.remove({ "MEOW", 2, 3, 4 });

	test.show_all_cars();

	return 0;
}
