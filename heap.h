#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"
#include <iostream>

void BuildHeap();
void Insert(int index);
void ExtractMin ();
void DecreaseKey(int index, double newKey);

#endif // HEAP_H