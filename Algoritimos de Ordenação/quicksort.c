#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void medianPivot(int *array, int left, int rigth) {
    int mid = (left+rigth)/2;
    if(array[mid] > array[rigth]) swap(array[mid], array[rigth]);
    if(array[left] > array[mid]) swap(array[left], array[mid]);
    if(array[rigth] > array[mid]) swap(array[rigth], array[mid]);
}

int partition(int *array, int left, int rigth){
    int pivot = array[rigth];
    int j = left;
    for(int k = left; k < rigth; k++){
        if(array[k] <= pivot){
            swap(array[k], array[j]);
            j++;
        }
    }
    swap(array[j], array[rigth]);
    return j;
}

void quicksort(int *array, int left, int rigth){
    if(rigth <= left) return;
    int x = partition(array, left, rigth);
    medianPivot(array, left, rigth);
    quicksort(array, left, x-1);
    quicksort(array, x+1, rigth);
}