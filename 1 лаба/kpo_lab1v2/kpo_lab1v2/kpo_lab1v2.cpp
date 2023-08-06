#include <iostream>
#include <string>
using namespace std;

void CheackValidnost(int day, int month, int year);
bool CheackLeapYear(int year);
void forInput(int* d, int* m, int* y);
int GetOrdinalNumber(int day, int month, int year);
int GetDaysBeforeBirthday(int day, int month, int year);

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
            cout << "Введите дату вашего дня рождения"<<endl;
            GetDaysBeforeBirthday(day, month, year);
            cout << endl;
        }break;
        case 4: main(); cout << endl; break;
        case 5: exit(0); break;
        default:
            cout << "Неизвестная операция, пожалуйста выберите цифру от 1 до 5" << endl; cout << endl;
            break;
            cout << endl;
        }
    } while (k != 5);
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
    char DAY[3];
    char MONTH[3];
    char YEAR[5];

    bool provD = false;
    bool provM = false;
    bool provY = false;

    int year = 0;
    int month = 0;
    int day = 0;
    int n = 3;

    cout << "Введите дату в формате ДДММГГГГ" << endl << "ДДММГГГГ = ";
    for (int i = 0; i < 8; i++) {
        cin >> cData[i];
    }
    DAY[0] = cData[0];
    DAY[1] = cData[1];

    MONTH[0] = cData[2];
    MONTH[1] = cData[3];

    YEAR[0] = cData[4];
    YEAR[1] = cData[5];
    YEAR[2] = cData[6];
    YEAR[3] = cData[7];

    DAY[2] = '\0';
    MONTH[2] = '\0';
    YEAR[4] = '\0';

    for (int i = 0; i < 2; i++) {
        switch (DAY[i])
        {
        case '0': provD = true; break;
        case '1': provD = true; break;
        case '2': provD = true; break;
        case '3': provD = true; break;
        case '4': provD = true; break;
        case '5': provD = true; break;
        case '6': provD = true; break;
        case '7': provD = true; break;
        case '8': provD = true; break;
        case '9': provD = true; break;
        default: provD = false;
        }
        if (provD == false) break;
    }

    for (int i = 0; i < 2; i++) {
        switch (MONTH[i])
        {
        case '0': provM = true; break;
        case '1': provM = true; break;
        case '2': provM = true; break;
        case '3': provM = true; break;
        case '4': provM = true; break;
        case '5': provM = true; break;
        case '6': provM = true; break;
        case '7': provM = true; break;
        case '8': provM = true; break;
        case '9': provM = true; break;
        default: provM = false;
        }
        if (provM == false) break;
    }

    for (int i = 0; i < 4; i++) {
        switch (YEAR[i])
        {
        case '0': provY = true; break;
        case '1': provY = true; break;
        case '2': provY = true; break;
        case '3': provY = true; break;
        case '4': provY = true; break;
        case '5': provY = true; break;
        case '6': provY = true; break;
        case '7': provY = true; break;
        case '8': provY = true; break;
        case '9': provY = true; break;
        default: provY = false;
        }
        if (provY == false) break;
    }

    if (provD && provM && provY) {
        day = stoi(DAY);
        month = stoi(MONTH);
        year = stoi(YEAR);
    }
    else {
        cout << "Некорректный ввод, попробуйте ещё раз.\n " << endl;
        forInput(&day, &month, &year);
    }
    delete[] cData;
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

        for (; year < (byear-1); year++) {
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
