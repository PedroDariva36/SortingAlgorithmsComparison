#include<stdio.h>
#include<stdlib.h>


int getMax(int *a,int n){
  int max = 0;
  for (int i = 0; i < n; i++) 
    if (a[i] > max) max = a[i];
  return max;
}

void countingSort(int *a, int max, int n){
    int *c = (int*) malloc(n * sizeof(int));
    int *b = (int*)  malloc((max +1)* sizeof(int));
  
    for (int i = 0; i < max + 1; i++) b[i] = 0;
    for (int i = 0; i < n; i++) b[a[i]]++;
    for (int i = 1; i < max +1; i++) b[i] += b[i-1];

    for (int i = n-1; i >= 0; i--) {
        b[a[i]] = b[a[i]] -1;
        c[b[a[i]]] = a[i];
    }
    for (int i = 0; i < n; i++) a[i] = c[i];
}

int main (int argc, char *argv[]){
    int n, *a;
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
 

    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    countingSort(a, getMax(a,n), n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
  
  return 0;
}
