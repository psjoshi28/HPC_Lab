//Fibonacci Series using Dynamic Programming #include<stdio.h>
#include<stdio.h>
#include <time.h>

int fib(int n)

{

	/* Declare an array to store Fibonacci numbers. */ int f[n+2]; // 1 extra to handle case, n = 0
	int i;

	/* 0th and 1st number of the series are 0 and 1*/ f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++)
	{
		/* Add the previous 2 numbers in the series and store it */
		f[i] = f[i-1] + f[i-2];
	}
	
	return f[n];
}



int main ()
{
	int n = 9; 
	clock_t start, finish;
    start = clock();
	printf("%d", fib(n));
	finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("\nExec time is: %lf",tt);
	return 0;
}

