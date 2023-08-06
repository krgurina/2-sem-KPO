#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;
//1
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;
struct Date {
	day dd;
	month mm;
	year yyyy;
};
bool operator == (Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd)
	{
		rezult = true;
	}
	else { rezult = false; }
	return rezult;
};
bool operator <(Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy < date2.yyyy || date1.yyyy == date2.yyyy && date1.mm < date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd)
	{
		rezult = true;
	}
	else { rezult = false; }
	return rezult;
};
bool operator >(Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy > date2.yyyy || date1.yyyy == date2.yyyy && date1.mm > date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd > date2.dd)
	{
		rezult = true;
	}
	else { rezult = false; }
	return rezult;
};


//2
typedef unsigned short metrazh;
typedef unsigned short kolichestvo_komnat;
typedef unsigned short year_postroiki;
typedef unsigned short etazh;
typedef unsigned char nalichie_kyxni; 
typedef unsigned char nalichie_vanna;
typedef unsigned char nalichie_tyaleta; 
typedef unsigned char nalichie_podvala;
typedef unsigned char nalichie_balkona;

struct parametri_kvartiri {
	metrazh metr;
	kolichestvo_komnat komnat;
	year_postroiki year;
	etazh et;
	nalichie_kyxni kyxni;
	nalichie_vanna vanna;
	nalichie_tyaleta tyalet;
	nalichie_podvala podval;
	nalichie_balkona balkon;
};
bool operator ==(parametri_kvartiri kv1, parametri_kvartiri kv2) {
	bool rezult;
	if (kv1.metr == kv2.metr) { 
		rezult = true; 
	}
	else { 
		rezult = false; 
	}
	return rezult;
}
bool operator >(parametri_kvartiri kv1, parametri_kvartiri kv2) {
	bool rezult;
	if (kv1.year > kv2.year) { 
		rezult = true; 
	}
	else { 
		rezult = false; 
	}
	return rezult;
}
int main()
{
	//1
	setlocale(LC_ALL, "rus");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1990 };
	Date date3 = { 7,1,1980 };
	if (date1 < date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 > date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date3) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	//2
	parametri_kvartiri kv1 = { 50, 2, 2002, 4, '+','+', '+','-' , '+'};
	parametri_kvartiri kv2 = { 65, 3, 2010, 7, '+','+', '+','-' , '+' };
	if (kv1 == kv2) { 
		cout << "kv1 и kv2 равны по площади" << endl;
	}
	else { 
		cout << "kv1 и kv2 не равны по площади" << endl;
	}
	if (kv1 > kv2) { 
		cout << "kv1 построена раньше, чем kv2" << endl;
	}
	else { 
		cout << "kv2 построена раньше, чем kv1" << endl; 
	}
	return 0;
}