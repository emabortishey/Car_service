#include "Header.h"
#include "Car_dealership.h"

using namespace std;

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

	return 0;
}
