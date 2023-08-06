#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
        //определить количество целых числе в vector равных заданному
    int target1 = 3;
    int num_items1 = count(v.begin(), v.end(), target1);
    cout << "Число: " << target1 << " количество: " << num_items1 << endl;
        //лямбда-выражение для подсчёта элементов, кратных 3
    int num_items3 = count_if(v.begin(), v.end(), [](int i) { return i % 3 == 0; });
    cout << "Количество элементов, кратных 3: " << num_items3 << endl;
    cout << "\nЛямбда, захват переменных " << endl;
        // лямбда-выражение, захват переменных
    for (auto i : v) [i]() {
        if (i % 3 == 0)
            cout << i << " ";
    }();
    cout << "\nЛямбда с параметрами" << endl;
    // вывод значений кратных 3. 
    // Значения будем передавать как параметр у обычной функции
    for (auto i : v) [](auto i) {
        if (i % 3 == 0)
            cout << i << " ";
    }(i);
    cout << "\nЛямбда без параметров" << endl;
    // вывод значений кратных 3. 
    //Значения передаюся через захват переменных при этом пропустим скобки для добавления параметров
    for (auto i : v) [i] {
        if (i % 3 == 0)
            cout << i << " ";
    }();

    cout << "\n Дополнительное задание 1" << endl;
    cout << "Введите число" << endl;
    int k;
    cin >> k;

    auto myLambda = [k]()
    {
        if (k > 0) return true;
        else return false;
    };
    cout << myLambda();

    //auto myLambda = [k] { return k > 0; };
    //cout << myLambda();

    cout << endl;
    
}