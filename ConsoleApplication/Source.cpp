#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <omp.h>
#include <locale.h>
#include <iostream>


using std::cout;

int main()
{
	int n; // num of threads
	scanf("%d", &n);

	srand(time(0));

	omp_set_num_threads(n);
#pragma omp parallel
	{
		if (omp_get_thread_num() % 2 == 1) {
			double value = (float)rand() / RAND_MAX * (23.0 * 3.0 - 23.0 - 3.0) + 23.0 - 3.0;
			printf("I am %d thread from %d threads, value %f\n", omp_get_thread_num(), n, value);
		}
	}

	return 0;
}