#include <iostream>
using namespace std;

namespace Varparm
{

	int ivarparm(int n, ...)
	{
		if (n == 0) return 0;
		int* p = &n + 1;
		int proizv = 1;
		for (int i = 0; i < n; i++) {
			proizv = p[i] * proizv;
		}
		return proizv;
	}

	// 
	int svarparm(short n, ...)
	{

		if (n == 0) return 0;
		int* p = (int*)&n + 1;
		int max = 0;
		for (int i = 0; i < n - 1; i++) {
			i = max;
			for (int j = i + 1; j < n; j++) {

				if (p[j] > p[max]) {
					max = j;
				}
			}
		}
		return p[max];
	}


	double fvarparm(float n, ...)
	{
		if (n == FLT_MAX) return 0;
		double sum = (double)n;
		double* p = (double*)(&n + 1);
		int i = 0;
		while (p[i] != (double)FLT_MAX) {

			sum += p[i];
			i++;
		}
		return sum;



		
	}


	double dvarparm(double n, ...)
	{
		if (n == DBL_MAX) return 0;
		double* p = (double*)(&n + 1);
		double sum = (double)n;
		int i = 0;
		while (p[i] != DBL_MAX) {

			sum += p[i];
			i++;
		}
		return sum;



		
	}

}