#include <iostream>
#include <windows.h>

using namespace std;

//21/////////////////////////////
int sum(int a,int b)
{
    return a+b;
}

////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    //2
    int x, y, z, s, n = 3;
    x = 9 + n;
    y = 10 + n;
    z = 11 + n;
    s = 1.0 + n;

    //4
    bool bf = false;// адрес    0x00EFFA4F  значение в памяти 00
    bool bt = true; // адрес    0x00EFFA43  значение в памяти 01

    //5
    char chfam = 'u';// адрес    0x00EFFA37  значение в памяти 75

    //6
    char chrusfam = 'у';// адрес   0x00EFFA2B  значение в памяти f3

    //7
    wchar_t wchfam = L'g';// адрес   0x00EFFA1C  значение в памяти 67 00

    //8
    wchar_t wchrusfam = L'г';// адрес    0x00EFFA10  значение в памяти 33 04

    //9
    //x=12=0x000c   
    //-x=-12=0x00f4     1000 1100пк     1111 0011ок     1111 0100дк
    short sh1 = 4;// адрес   0x00EFFA04  значение в памяти 0c 00
    short sh2 = -4;// адрес   0x0096FCE8  значение в памяти f4 00
  
    
    //10
    short shmax = 0x7fff; // в 10-тичной с/с 32767
    short shmin = 0x8000; // в 10-тичной с/с -32768
    
    //11
    unsigned short unshmax = 0xffff; // в 10-тичной с/с 65535
    unsigned short unshmin = 0x0000; // в 10-тичной с/с 0

    //12
    //y=13=0x000d
    //-y=-13=0x00f3     1000 1101пк     1111 0010ок  1111 0011дк
    int i1 = 13; // адрес   0x00EFF9BC  значение в памяти 0d 00 00 00
    int i2 = -13; // адрес   0x0096FCA0  значение в памяти f3 00 00 00 
    
    //13
    int imax = 0x7FFFFFFF; // в 10-тичной с/с 2147483647
    int imin = 0x80000000; // в 10-тичной с/с -2147483648

    //14
    unsigned int unimax = 0xffffffff; // в 10 - тичной с/с 4294967295
    unsigned int unimin = 0x00000000; // в 10 - тичной с/с 0

    //15   
    //z=14=0x000e
    //-z=-14=0x00f2     1000 1110пк       1111 0001ок       1111 0010дк
    long lz1 = 14;    // адрес   0x010FFAF0  значение в памяти 0e 00 00 00
    long lz2 = -14;    // адрес   0x0096FC58  значение в памяти f2 00 00 00 

    //16
    long lmax = 0x7FFFFFFF; // в 10 - тичной с/с 2147483647
    long lmin = 0x80000000; // в 10 - тичной с/с -2147483648

    //17
    unsigned long unlmax = 0xffffffff;// в 10 - тичной с/с 4294967295
    unsigned long unlmin = 0x00000000;// в 10 - тичной с/с 0

    //18
    // 4(10)=100(2) сдвиг на 2 разряда
    // 127+2=129(экспонента)    129=10000001
    //s=4=0x0004        0 10000001 00000000000000000000000  
    //-s=-4=0x00fc      1 10000001 00000000000000000000000  
    float fs1 = 4.0f;  // адрес   0x010FFAA8  значение в памяти 00 00 80 40
    float fs2 = -4.0f;  // адрес   0x010FFAA8  значение в памяти  

    //19
    float big = 1.0, little = -1.0, nan;
    big /= 0;// 1.#INF
    little /= 0;// -1.#INF
    nan = sqrt(-1);// -1.#IND

    //20 ///////////////////////////////////////////////////////////////
    double d = 2.0;

    char* pchfam = &chfam;
    wchar_t* pwchfam = &wchfam;
    short* p_sh1 = &sh1;
    int* pi1 = &i1;
    float* pfs1 = &fs1;
    double* pd = &d;

    cout << pchfam << " " << pwchfam << " " << p_sh1 << " " << pi1 << " " << pfs1 << " " << pd << endl;

    pchfam += 3; pwchfam += 3; p_sh1 += 3; pi1 += 3; pfs1 += 3; pd += 3;

    cout << pchfam << " " << pwchfam << " " << p_sh1 << " " << pi1 << " " << pfs1 << " " << pd << endl;

    //21////
    int a = 15;
    int b = 5;
    sum(a, b);  //адрес 0x00007FF6A75C23F0
    int (*psum)(int a, int b);//psum содержит в себе адрес вхождения в функцию sum
    psum = &sum;// отображение значения psum в памяти   e0 11 5c a7 f6 7f 00 00
        
    //  адрес       sum      0x00007FF6A75C23F0         
    //  значения    psum     0x00007FF6A75C23F0       
    //  адрес      &psum     0x000000b5bf4ff9a8
    
    
    return 0;
}

