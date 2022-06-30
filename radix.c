#include <stdio.h>
#include <stdlib.h>

int getMax(int *vec, int n){
  int max = 0;
  for (int i = 0; i < n; i++){
    if(vec[i] > 0) max = vec[i]; 
  }
  return max;
}

void counting(int *vec, int n,int position){
  int *aux = (int*) malloc(n * sizeof(int));
  int count[10] = {0,0,0,0,0,0,0,0,0,0};

  for (int i = 0; i < n; i++) count[(vec[i]/position)%10]++;
  for (int i = 1; i < 10; i++) count[i] = count[i] + count[i-1];

  for (int i = n-1; i >= 0; i--) {
    int dig = (vec[i]/position)%10;
    count[dig]--;
    aux[count[dig]] = vec[i];
  }
    
  for (int i = 0; i < n; i++) vec[i] = aux[i];
}

void radix(int *vec,int n){
   int max = getMax(vec, n);
   for (int pos = 1; max/pos > 0; pos *= 10) counting(vec, n, pos);
}

int main (int argc, char *argv[]){
  int n, *vec;
  scanf("%d",&n);
  vec = (int *) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d",&vec[i]);
  
  radix(vec,n);

  for (int i = 0; i < n; i++) 
    printf("%d ", vec[i]);
  printf("\n"); 

  return 0;
}
