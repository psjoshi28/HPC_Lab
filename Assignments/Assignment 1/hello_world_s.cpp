#include <stdio.h>
#include <omp.h>
#include<time.h>

int main() {
	clock_t start, finish;
    start = clock();
    
    for(int i=0;i<16;i++)
    	printf("Hello World\n");
    
    finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("Exec time is: %lf",tt);
    return 0;
}

