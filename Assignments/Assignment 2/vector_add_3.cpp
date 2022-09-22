#include<stdio.h>
#include<conio.h>
#include <time.h>
int main() 
{
 clock_t start, finish;
 start = clock();
 int a[10], b[10]; /* vectors to be added */
 int c[10]; /* result vector */
 int n, i;
 /* read vectors a and b */
 printf("Enter vector size: ");
 scanf("%d", &n);
 printf("Enter elements of vector a:\n");
 for (i = 0; i < n; i++)
   scanf("%d", &a[i]);
   printf("Enter elements of vector b:\n");
   for (i = 0; i < n; i++)
    scanf("%d", &b[i]);
    /* perform vector addition */
    for (i = 0; i < n; i++)
      c[i] = a[i] + b[i];
    /* print addition vector C */
    printf("Addition vector:\n");
    for (i = 0; i < n; i++)
      printf("%d ", c[i]);
      getch();
 finish = clock();
 double tt = (double)(finish-start)/CLOCKS_PER_SEC;
 printf("Exec time is: %lf",tt);
}
