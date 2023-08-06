#include "Call.h"
#include <iostream>
using namespace std;
using namespace Call;

int main() {
	int y = 8;
	int sum1 = cdevl(1, 2, 3);
	cout << sum1 << endl;
	int pr = cstd(y, 9, 5);
	cout << pr << endl;
	int sum2 = cfst(7, 4, 6, 0);
	cout << sum2 << endl;
	return 0;
}