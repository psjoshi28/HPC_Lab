#include<stdio.h>
#include<omp.h>
#include<time.h>

int main()
{
	int i,sum=0;
	int thread_sum[4];
	omp_set_num_threads(4);
	clock_t start, finish;
    start = clock();
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		thread_sum[ID] = 0;
		#pragma omp for
		for(i=1;i<=100;i++)
		{
			printf ("Square of %d is %d printed by thread %d\n", i, (i*i),ID);
			thread_sum[ID] += (i*i);
		}
	}
	for(i=0;i<4;i++)
	{
		sum += thread_sum[i];
	}
	printf("Sum = %d",sum);
	finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("\nExec time is: %lf",tt);
	return 0;
}
