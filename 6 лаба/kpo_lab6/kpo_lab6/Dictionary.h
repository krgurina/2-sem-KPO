#pragma once

#include <cstring>
#include <string>
#include<iostream>

#define DICTNAMEMAXSIZE 20	//максимальный размер словаря
#define DICTMAXSIZE		100	//максимальная ёмкость словаря
#define ENTRYNAMEMAXSIZE 30	//максимальная длина имени в словаре

#define THROW01 "Create: превышен размер имени словаря "
#define THROW02 "Create: превышен размер максимальной ёмкости словаря "
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry:дублирование идефикатора"
#define THROW05 "GetEntry: не найден элемент "
#define THROW06 "DelEntry: не найден элемент "
#define THROW07 "UpdEntry: не найден элемент "
#define THROW08 "UpdEntry: дублирование идефикатора "



namespace Dictionary
{
	struct Entry {	// элемент словаря
		int id;							//идентификатор(уникальный)
		char name[ENTRYNAMEMAXSIZE];	//символьная информация
	};

	struct Instance		//экземпляр словаря
	{
		char name[DICTNAMEMAXSIZE];		//наименование словаря
		int maxsize;		//максимальная ёмкость словаря	
		int size;			//текущий размер словаря < DICTMAXSIZE
		//Entry* dictionary;	//массив элементов словаря
		Entry* dictionary[DICTMAXSIZE];
	};
	/////////
	// inst объект структуры Instance
	Instance Create(char name[DICTNAMEMAXSIZE], int size);	//создать словарь
	void AddEntry(Instance& inst, Entry ed);				//добавить элемент в словарь
	void DelEntry(Instance& inst, int id);					//удалить элемент словаря
	void UpdEntry(Instance& inst, int id, Entry new_ed);	//изменить элемент словаря
	Entry GetEntry(Instance& inst, int id);					//получить элемент словаря по id
	void Print(Instance& d);								//печать словаря
	void Delete(Instance& d);								//удаление словаря
}
