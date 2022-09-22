#include <stdio.h>
#include<time.h>

using namespace std;

int main()
{
	int i=1,sum=0;
	clock_t start, finish;
    start = clock();
	for(;i<=100;i++)
	{
		printf("Square of %d is %d \n",i,(i*i));
		sum += (i*i);
	}
	printf("Sum of squares: %d",sum);
	finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("\nExec time is: %lf",tt);
}
