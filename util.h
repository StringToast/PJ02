#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include "data_structures.h"

using namespace std;

//read input and initialize V and pHeap
void Read(const char* filename, HEAP*& pHeap, ELEMENT**& V);

//write v to the output file
void Write(const char* filename, ELEMENT** V, int capacity);

void printArray(ELEMENT** V, int capacity);

void printHeap(HEAP* pHeap);
#endif
