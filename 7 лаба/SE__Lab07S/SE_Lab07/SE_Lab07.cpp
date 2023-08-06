#include <iostream>
#include <stdio.h>
#include <fstream>
#include "F:\лабы\КПО\7 лаба\SE__Lab07S\SEP_Lab07L\Dictionary.h"
using namespace std;
using namespace Dictionary;
#pragma comment (lib, "F:\\лабы\\КПО\\7 лаба\\SE__Lab07S\\Debug\\SE_Lab07L.lib")

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		Instance d1 = Create((char*)"Преподаватели", 5);
		Entry e1 = { 1,"Белодед" }, e2 = { 2,"Барковский" }, e3 = { 3,"Смелов" }, e4 = { 4, "Гринюк" }, e5 = { 5, "Мущук" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		AddEntry(d1, e5);
		Entry getE = GetEntry(d1, 5);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Жиляк" };
		UpdEntry(d1, 3, newentry1);
		DelEntry(d1, 4);
		Print(d1);

		Instance d2 = Create((char*)"Студенты", 5);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 4, "Гурина" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}
