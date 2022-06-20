int _SWAPS = 0;
int _COMPS = 0;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    _SWAPS++;
}

void bubbleSort(int* vet, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i; j < n; j++){
            if(vet[j] < vet[i]){
                swap(&vet[i],&vet[j]);
                _COMPS++;
            }
        }
    }
    return;
}

void selectionSort(int*vet, int size){
    int min, temp, tempIndex;
    for(int i = 0; i < size-1; i++){
        min = vet[i];
        tempIndex = i;
        for(int j = i; j<size; j++)
        {
            
            if(min > vet[j]){
                _COMPS++;
                min = vet[j];
                tempIndex = j;
            }
        }
        _SWAPS++;
        temp = vet[i];
        vet[i] = min;
        vet[tempIndex] = temp;
    }
    return;
}

void insertionSort(int* vet, int size)
{
    for (int i = 1; i < size; i++) {
        int key = vet[i];
        int j = i - 1;

        while (key < vet[j] && j >= 0) {
            _COMPS = _COMPS + 2;
            vet[j + 1] = vet[j];
            --j;
        }

        vet[j + 1] = key;
    }
    return;
}
