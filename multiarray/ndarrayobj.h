#ifndef CNDARRAY_MULTIARRAY_NDARRAYOBJ_H_
#define CNDARRAY_MULTIARRAY_NDARRAYOBJ_H_

#include <stdio.h>
#include <stdlib.h>

/*
    ndarray struct
*/
typedef struct ndarray{
    // points to the first value of the ndarray
    char *data;

    // size of the ndarray (multiplication of the dimensions)
    size_t size;

    // dimensions of the ndarray
    size_t *dimensions;

    // number of dimensions of the ndarray
    size_t nd;

    // the number of bytes to go to the next value in each dimension
    size_t *strides;
} Ndarray;

Ndarray *Ndarray_Alloc(size_t*, size_t, size_t);

#endif