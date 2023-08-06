#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

void CheackValidnost(int day, int month, int year);
bool CheackLeapYear(int year);
void forInput(int* d, int* m, int* y);
int GetOrdinalNumber(int day, int month, int year);
int GetDaysBeforeBirthday(int day, int month, int year);
int Month(int month);
//int ProgrammerDay(int day, int month, int year);
int DayDev(int day, int mon, int year);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "RUS");
    int year = 0;
    int month = 0;
    int day = 0;

    forInput(&day, &month, &year);

    int k;
    do
    {
        cout << "Выберите функцию:\n 1 - определить, является ли введенный год високосным\n 2 - вычислить порядковый номер введенного дня в году\n 3 - вычислить сколько дней осталось до ближайшего дня вашего рождения\n 4 - ввести новую дату\n 5 - вывести название месяца\n 6 - \n 7 - выход" << endl;
        cin >> k; cout << endl;
        switch (k)
        {
        case 1: {
            if (CheackLeapYear(year))
                cout << "Год високосный" << endl;
            else
                cout << "Год не високосный" << endl;
            cout << endl;
        } break;
        case 2: {
            cout << "Порядковый номер дня: " << GetOrdinalNumber(day, month, year) << endl; cout << endl;
        }
              break;
        case 3: {
            cout << "Введите дату вашего дня рождения" << endl;
            GetDaysBeforeBirthday(day, month, year);
            cout << endl;
        }break;
        case 4: main(); cout << endl; break;
        case 5: {
            cout << "Название месяца: " << Month(month) << endl; 
            break;
        }









        case 7: exit(0); break;
        default:
            cout << "Неизвестная операция, пожалуйста выберите цифру от 1 до 5" << endl; cout << endl;
            break;
            cout << endl;
        }
    } while (k != 7);
}

bool CheackLeapYear(int year) {
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

void forInput(int* d, int* m, int* y) {
    char* cData = new char[8];
    int* iData = new int[8];
    int year = 0;
    int month = 0;
    int day = 0;
    int n = 3;
    char symbol;

    cout << "Введите дату в формате ДДММГГГГ" << endl << "ДДММГГГГ = ";
    for (int i = 0; i < 8; i++) {
        cin >> cData[i];  
    }

    for (int i = 0; i < 8; i++) {     
        symbol = cData[i];
        if ((symbol >= 0 && symbol <= 47) || (symbol >= 58 && symbol <= 255)) {
            cout << "Неправильно введена дата! Попробуйте еще раз" << endl;
            delete[] cData;
            forInput(&day, &month, &year);
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        iData[i] = cData[i] - '0';
    }
    delete[] cData;


    for (int i = 4; i < 8; i++, n--) {
        year += iData[i] * pow(10, n);
    }
    n = 1;
    for (int i = 0; i < 2; i++) {
        day += iData[i] * pow(10, n);
        n--;
    }					// Отделение дня, месяца и года от массива
    n = 1;
    for (int i = 2; i < 4; i++) {
        month += iData[i] * pow(10, n);
        n--;
    }
    *d = day;
    *m = month;
    *y = year;
    delete[] iData;
    //проверка ввода
    CheackValidnost(day, month, year);
}

void CheackValidnost(int day, int month, int year)
{
    int numberofdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (CheackLeapYear(year))
        numberofdays[1] = 29;

    if (day > numberofdays[month - 1] || year < 1) {
        cout << "Некорректный ввод, попробуйте ещё раз.\n " << endl;
        forInput(&day, &month, &year);
    }

}
int GetOrdinalNumber(int day, int month, int year)
{
    int ordinal_number = 0;
    int numberofdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (CheackLeapYear(year))
        numberofdays[1] = 29;

    for (int i = 0; i < month - 1; i++)
    {
        ordinal_number += numberofdays[i];
    }
    ordinal_number += day;
    cout << endl;
    return ordinal_number;
}
int GetDaysBeforeBirthday(int day, int month, int year) {

    int CurrentOrdinalNumber;
    CurrentOrdinalNumber = GetOrdinalNumber(day, month, year);

    int bday = 0, bmonth = 0, byear = 0;
    forInput(&bday, &bmonth, &byear);
    //
    int BirthdayOrdinalNumber = 0;
    int BeforeBirthday = 0;
    int AllDays = 0;
    if (CheackLeapYear(year)) {
        AllDays = 366;
    }
    else {
        AllDays = 365;
    }

    if (year < byear) {
        cout << "К сожалению вы ещё не роделись";
        BeforeBirthday = AllDays - GetOrdinalNumber(day, month, year);

        for (; year < (byear - 1); year++) {
            if (CheackLeapYear(year)) {
                BeforeBirthday += 366;
            }
            else {
                BeforeBirthday += 365;
            }
        }
        BeforeBirthday += GetOrdinalNumber(bday, bmonth, year);
        cout << "Дней до вашего рождения: " << BeforeBirthday << endl;
    }
    else {
        BirthdayOrdinalNumber = GetOrdinalNumber(bday, bmonth, year);
        BeforeBirthday = BirthdayOrdinalNumber - CurrentOrdinalNumber;
        if (BeforeBirthday > 0)
        {
            cout << "Количество дней до дня рождения: " << BeforeBirthday << endl;
        }
        else if (BeforeBirthday < 0)
        {
            BeforeBirthday = AllDays - (CurrentOrdinalNumber - BirthdayOrdinalNumber);
            cout << "Количество дней до дня рождения: " << BeforeBirthday << endl;
        }
        else if (BeforeBirthday == 0)
        {
            cout << "Ура! Сегодня ваш день рождения!" << endl;
        }
    }
    return BeforeBirthday;
}
//
//int ProgrammerDay(int day, int month, int year) {
//    int number_pday = 256;
//    if (CheackLeapYear(year)) {
//
//    }
//        
//}

int Month(int month) {

    string names[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    cout << "Название месяца: " << names[month - 1] << endl;
    return 0;


}

//
//int DayDev(int day, int mon, int year) // вводимые параметры
//{
//    string monArr[]{ "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентября", "ноябрь", "декабрь" };
//    string Month_sb;
//
//    int DevDay = 256, value = 0, var = 0;
//    int DayNumberVis[]{ 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
//
//    if (year % 4 == 0 || year % 400 == 0 || year % 100 == 0)
//    {
//        value = 0;
//    }
//    else value--;
//
//    for (int i = 0; i < 12; i++)
//    {
//        if (DevDay > value)
//        {
//            value += DayNumberVis[i];
//            var++;
//        }
//        else
//        {
//            value = value - DevDay;
//            value = DayNumberVis[var] - value;
//            break;
//        }
//    }
//    Month_sb = monArr[var - 1]; // присвоение числу месяца его названия
//    cout << "День программиста в этом году отмечается " << value << " " << Month_sb << endl;
//    return 0;
//}