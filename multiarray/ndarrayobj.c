#include <stdio.h>
#include <stdlib.h>

#include "ndarrayobj.h"

Ndarray *Ndarray_Alloc(size_t *dims, size_t nd, size_t elsize){
    // iterators
    size_t i, j;

    Ndarray *arr = (Ndarray*)malloc(sizeof(Ndarray));

    if(!arr)
        return NULL;

    arr->size = 1;
    for(i = 0; i < nd; i++)
        arr->size *= dims[i];

    arr->dimensions = dims;
    arr->nd = nd;
    
    arr->strides = malloc(sizeof(size_t) * nd);

    if(!arr->strides)
        return NULL;

    for(i = 0; i < nd; i++){
        arr->strides[i] = 0;
        for(j = i; j < nd; j++){
            arr->strides[i] += arr->dimensions[j];
        }
        arr->strides[i] *= elsize;
    }
}


