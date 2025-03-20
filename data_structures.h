#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>

using namespace std;

//element structure, for my understanding an element is a node of the heap.
//it has an index within the array, a key value, and a index in the heap-array
typedef struct TAG_ELEMENT{
       int index; //index of the element
       double key; //key value of the element
       int pos; //position in the heap-array, 0 if not in the heap.
	} ELEMENT;
//define heap structure
typedef struct TAG_HEAP{
	int capacity;
	int size;
	int *H;

} HEAP;
#endif

