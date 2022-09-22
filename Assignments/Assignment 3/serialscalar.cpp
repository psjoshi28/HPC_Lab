#include <stdio.h>
#include <omp.h>
#include <time.h>
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {0};
    int i, c = 5;
    clock_t start, finish;
    start = clock();
    for (i = 0; i < 10; i++)
    {
        b[i] = a[i] + c;
    }
    printf("\nVector Scalar Addition\n");
    for (int i = 0; i < 10; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }
    finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("Exec time is: %lf",tt);
    return 0;
}
