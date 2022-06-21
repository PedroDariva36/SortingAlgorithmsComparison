#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include "sort.h"

struct timeval stop, start;


int main(){
    
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    gettimeofday(&start, NULL);
    
    //bubbleSort(vet,n);
    //selectionSort(vet,n);
    insertionSort(vet,n);

    gettimeofday(&stop, NULL);
    double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f\n",secs);
    printf("Total comps: %ld \nTotal Swaps: %ld \n",_COMPS, _SWAPS);

    //printf("%ld\n", n);
    //for (int i = 0; i < n; i++) 
    //    printf("%ld\n", vet[i]);
    

    return 0;
}