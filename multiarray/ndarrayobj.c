#include <stdio.h>
#include <stdlib.h>

#include "ndarrayobj.h"
#include "ndarraytypes.h"

/*!
 * @param dims the dimensions of your ndarray
 * @param nd the number of dimensions, the size of `dims`
 * @param elsize the size in bytes of the elements to allocate
 * @return a ndarray allocated
*/
Ndarray *Ndarray_Alloc(size_t *dims, size_t nd, size_t elsize, int type){
    // initialize the iterators
    size_t i, j;

    // allocate the array
    Ndarray *arr = (Ndarray*)malloc(sizeof(Ndarray));

    // if the allocation fails, return NULL
    if(!arr)
        return NULL;

    // describer creation
    arr->eldescr.elsize = elsize;
    arr->eldescr.type = type;

    // creates the size, multiplication of the dimensions
    arr->size = 1;
    for(i = 0; i < nd; i++)
        arr->size *= dims[i];

    arr->dimensions = dims;
    arr->nd = nd;
    
    arr->strides = malloc(sizeof(size_t) * nd);

    // if allocate fails, return NULL
    if(!arr->strides)
        return NULL;

    // creates the strides
    for(i = 0; i < nd; i++){
        arr->strides[i] = 0;
        for(j = i; j < nd; j++){
            arr->strides[i] += arr->dimensions[j];
        }
        arr->strides[i] *= elsize;
    }
}


