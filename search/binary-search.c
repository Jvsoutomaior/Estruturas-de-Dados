#include <stdlib.h>

int binary_search( int *array, int size, int x){
    int min = -1;
    int max = size;
    int m;
    while(min < max-1){
        m = (min + max)/2;
        if(array[m] < x) min = m;
        else max = m;
    }
    return max;
}