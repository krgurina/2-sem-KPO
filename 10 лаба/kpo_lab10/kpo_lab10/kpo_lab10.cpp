
#include <iostream>
#include <locale>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "ivarparm с 1 параметром: " << ivarparm(1, 2) << '\n';
	cout << "ivarparm с 2 параметрами: " << ivarparm(2, 8, 2) << '\n';
	cout << "ivarparm с 3 параметрами: " << ivarparm(3, 3, 3,4) << '\n';
	cout << "ivarparm с 7 параметрами: " << ivarparm(7, 2, 4, 2, 5, 8, 3, 6) << "\n\n";

	cout << "svarparm с 1 параметром: " << svarparm(1, 4) << '\n';
	cout << "svarparm с 2 параметрами: " << svarparm(2, 3, 5) << '\n';
	cout << "svarparm с 3 параметрами: " << svarparm(3, 2, 7, 8) << '\n';
	cout << "svarparm с 7 параметрами: " << svarparm(3, 7, 4, 2, 4, 8, 3) << "\n\n";

	cout << "fvarparm с 1 параметром: " << fvarparm(1.0, FLT_MAX) << '\n';
	cout << "fvarparm с 2 параметрами: " << fvarparm(1.0, 1.5, FLT_MAX) << '\n';
	cout << "fvarparm с 3 параметрами: " << fvarparm(1.0, 2.4, 3.2, FLT_MAX) << '\n';



	cout << "fvarparm с 7 параметрами: " << fvarparm(1.0, 1.5, 2.3, 3.5, 4.0, 5.0, 6.0, FLT_MAX) << "\n\n";

	cout << "dvarparm с 1 параметром: " << dvarparm(1.0, DBL_MAX) << '\n';
	cout << "dvarparm с 2 параметрами: " << dvarparm(1.0, 4.5, DBL_MAX) << '\n';
	cout << "dvarparm с 3 параметрами: " << dvarparm(1.0, 1.5, 2.0, DBL_MAX) << '\n';
	cout << "dvarparm с 7 параметрами: " << dvarparm(1.0, 1.5, 2.3, 3.5, 4.0, 5.0, 6.0, DBL_MAX) << "\n\n";

}
