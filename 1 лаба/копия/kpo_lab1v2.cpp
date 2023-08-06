#include <iostream>
using namespace std;



void forInput(int* d, int* m, int* y) {
    char* cData = new char[8];
    int* iData = new int[8];
    int year = 0;
    int month = 0;
    int day = 0;
    int n = 3;

    cout << endl << "Введите дату в формате ДДММГГГГ"
        << endl << "ДДММГГГГ = ";
    for (int i = 0; i < 8; i++) {
        cin >> cData[i];
    }
    for (int i = 0; i < 8; i++) {
        iData[i] = cData[i] - '0';
        if (iData[i] > 9 || iData < 0) {
            cout << "Неправильно введена дата! Попробуйте еще раз" << endl;
            //main();
            
        }
    }
    delete[] cData;

    // Отделение дня, месяца и года от массива
    for (int i = 4; i < 8; i++, n--) {
        year += iData[i] * pow(10, n);
    }
    n = 1;
    for (int i = 0; i < 2; i++) {
        day += iData[i] * pow(10, n);
        n--;
    }
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
    bool LeapYear;
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        LeapYear = true;
    else
        LeapYear = false;

    if (day, month, year < 1 || month>12 || day > 32 || (month == 4|| month == 6|| month == 9||month == 11) && day > 30 || month == 2 && LeapYear == false && day > 28 || month == 2 && LeapYear == true && day > 29) {
        cout << "Некорректный ввод, попробуйте ещё раз " << endl;
        forInput(&day, &month, &year);
    }
}



int CheackLeapYear(int year) {
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        cout << "Год високосный " << endl;
    else
        cout << "Год не високосный " << endl;
    return 0;
}



int GetOrdinalNumber(int day, int month, int year)
{
    int ordinal_number = 0;
    int numberofdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
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

    int bday, bmonth;
    do {
    cout << "Введите день вашего рождения: " << endl;
    
    
        cin >> bday;
    } while (bday < 0 || bday>31);
    do{
    cout << "Введите месяц вашего рождения(1-12): " << endl;
    cin >> bmonth;
    } while (bmonth < 0 || bmonth>12);



    int BirthdayOrdinalNumber;
    BirthdayOrdinalNumber = GetOrdinalNumber(bday, bmonth, year);


    int BeforeBirthday;
    BeforeBirthday = BirthdayOrdinalNumber - CurrentOrdinalNumber;
    if (BeforeBirthday > 0)
    {
        cout << "Количество дней до дня рождения: " << BeforeBirthday << endl;
    }
    else if (BeforeBirthday < 0)
    {
        BeforeBirthday = 365 - (CurrentOrdinalNumber - BirthdayOrdinalNumber);
        cout << "Количество дней до дня рождения: " << BeforeBirthday << endl;
    }
    else if (BeforeBirthday == 0)
    {
        cout << "День рождения сегодня!" << endl;
    }
    return BeforeBirthday;
}




int main()
{
    setlocale(LC_CTYPE, "RUS");

    int year = 0;
    int month = 0;
    int day = 0;

    forInput(&day, &month, &year);


    int k;
    do
    {
        cout << "Выберите функцию:\n 1 - определить, является ли введенный год високосным\n 2 - вычислить порядковый номер введенного дня в году\n 3 - вычислить сколько дней осталось до ближайшего дня вашего рождения\n 4 - ввести новую дату\n 5 - выход" << endl;

        cin >> k;
        cout << endl;

        switch (k)
        {
        case 1: CheackLeapYear(year); cout << endl; break;
        case 2: {
            cout << "Порядковый номер дня: " << GetOrdinalNumber(day, month, year) << endl; cout << endl;
        }
              break;
        case 3: GetDaysBeforeBirthday(day, month, year); cout << endl; break;
        case 4: main(); cout << endl; break;
        case 5: exit(0); break;
        default:
            cout << "Неизвестная операция, пожалуйста выберите цифру от 1 до 5" << endl; cout << endl;
            break;
            cout << endl;

        }
    } while (k != 5);







}