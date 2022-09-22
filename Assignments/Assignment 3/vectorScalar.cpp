#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 100
int main()
{
    int a[N];
    int b[N];
    int i, c = 5;
    clock_t start, finish;
    start = clock();
    for(i=0;i<N;i++)
	{
       a[i]= i+1;
	}
	for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
	#pragma omp parallel for shared(a, b) private(c) num_threads(5)
	for (i = 0; i < N; i++)
	{
	    b[i] = a[i] + c;
	}
    printf("\nVector Scalar Addition\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", b[i]);
    }
    finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("Exec time is: %lf",tt);
    return 0;
}
