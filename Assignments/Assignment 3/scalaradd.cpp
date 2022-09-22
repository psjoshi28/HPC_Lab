#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
	int tid;
	int i,j;
	int rows = 200,cols=1;
	int a[rows][cols];
	int scalar;
	int c[rows][cols];
	
	int *d,*f;

	for(i=0;i<rows;i++)
	{
	  for(j=0;j<cols;j++)
	       a[i][j] = i+1;
	}
	printf("Enter value of scalar:\n");
	scanf("%d",&scalar);
	d=(int *)malloc(sizeof(int)*rows*cols);
	f=(int *)malloc(sizeof(int)*rows*cols);
	
	d=(int *)a;
	f=(int *)c;
	
	//Concurrent or parallel matrix addition
	#pragma omp parallel num_threads(rows*cols)
	  {
	    tid=omp_get_thread_num();
	    f[tid]=d[tid]+scalar;
	  }
	
	for (int i = 0; i < rows; i++)
	{
	   for (int j = 0; j < cols; j++)
	   {
	      printf("%d ",c[i][j]);
	   }
	    
	   printf("\t");
	}
	return 0;
}
