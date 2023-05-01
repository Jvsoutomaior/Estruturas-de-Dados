#include <stdio.h>
#include <stdlib.h>

void merge(int *arry, int left, int mid, int rigth){
    int *arry2 = malloc((rigth-left+1)*sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;
    while( i <= mid && j <= rigth){
        if(arry[i] <= arry[j]) arry2[k++] = arry[i++];
        else arry2[k++] = arry[j++];
    }
    while( i <= mid ) arry2[k++] = arry[i++];
    while( j <= rigth ) arry2[k++] = arry[j++];
    for(int i = left; i <= rigth; i++) arry[i] = arry2[k++];
    free(arry2);
}

void mergersort(int *arry, int left, int rigth){
    if(left >= rigth) return;
    int mid = (left+rigth)/2;
    mergersort(arry, left, mid);
    mergersort(arry, mid+1, rigth);
    merge(arry, left, mid, rigth);
}