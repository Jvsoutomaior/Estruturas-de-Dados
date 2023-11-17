#include <stdio.h>

int ordenacao(int *array, int size){
    int num, j;
    for(int i = 0; i < size; i++){
        num = array[i];
        for(j = i-1; j >= 0 && array[j] > num; j++){
            array[j+1] = array[j];
        }
        array[j+1] = num;
    }
}
