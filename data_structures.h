#include <iostream>

typedef struct TAG_ELEMENT{
    int index;                      // index of the element in the element array
    double key;                     // value of the element 
    int pos;                        // this is for the position of the element in the HEAP-Array
}ELEMENT;

typedef struct TAG_HEAP{
    int capacity;                   // capacity of the whole tree
    int size;                       // size of the tree
    int *H;                         // array of indices/pointers to the Element array
}HEAP;

