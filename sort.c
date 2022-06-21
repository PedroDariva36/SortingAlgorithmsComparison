long _SWAPS = 0;
long _COMPS = 0;

void swap(int * xp, int * yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    _SWAPS++;
}

void bubbleSort(int * vet, int n){
    int flag;
    for (int i = 0; i < n - 1; i++){
        flag = 0;
        for (int j = i; j < n; j++){
            _COMPS++;
            if(vet[j] < vet[i]){
                swap(&vet[i],&vet[j]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void selectionSort(int * vet, int size){
    int min, temp, tempIndex;
    for(int i = 0; i < size-1; i++){
        min = vet[i];
        tempIndex = i;
        for(int j = i; j<size; j++)
        {
            _COMPS++;
            if(min > vet[j]){
                min = vet[j];
                tempIndex = j;
            }
        }
        _SWAPS++;
        temp = vet[i];
        vet[i] = min;
        vet[tempIndex] = temp;
    }
}

void insertionSort(int* vet, int size)
{
    for (int i = 1; i < size; i++) {
        int key = vet[i];
        int j = i - 1;

        _COMPS++;
        while (key < vet[j] && j >= 0) {
            _COMPS++;
            vet[j + 1] = vet[j];
            _SWAPS++;
            --j;
        }

        vet[j + 1] = key;
    }
    return;
}
