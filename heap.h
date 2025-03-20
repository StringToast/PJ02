#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"
void MinHeapify(HEAP* pHeap, ELEMENT** V, int index);

void BuildHeap(HEAP* pHeap, ELEMENT** V, int n);

void Insert(HEAP* pHeap, ELEMENT** V, int index);

ELEMENT* ExtractMin(HEAP* pHeap, ELEMENT** V);

void DecreaseKey(HEAP* pHeap, ELEMENT** V, int index, double newKey);
#endif
