#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

int main()
{
clock_t start, finish;
start = clock();
int tid;
int i,j;
int rows,cols;

printf("Enter Number of Rows of matrices\n");
scanf("%d",&rows);
printf("Enter Number of Columns of matrices\n");
scanf("%d",&cols);

int a[rows][cols];
int b[rows][cols];
int c[rows][cols];

int *d,*e,*f;

for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       a[i][j] = i+1;
    }

for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       b[i][j] = i+1;
    }

d=(int *)malloc(sizeof(int)*rows*cols);
e=(int *)malloc(sizeof(int)*rows*cols);
f=(int *)malloc(sizeof(int)*rows*cols);

d=(int *)a;
e=(int *)b;
f=(int *)c;

//Concurrent or parallel matrix addition
#pragma omp parallel num_threads(rows*cols)
  {
    tid=omp_get_thread_num();
    f[tid]=d[tid]+e[tid];
  }

//printf("Values of Resultant Matrix C are as follows:\n");
for (int i = 0; i < rows; i++)
{
   for (int j = 0; j < cols; j++)
   {
      printf("%d ",c[i][j]);
   }
    
   // Newline for new row
   printf("\n");
}
finish = clock();
double tt = (double)(finish-start)/CLOCKS_PER_SEC;
printf("Exec time is: %lf",tt);
return 0;
}
