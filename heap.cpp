#include "heap.h"
#include <iostream>

void MinHeapify(HEAP* pHeap, ELEMENT** V, int index){
	//first find the left and right, then assume that the current node is the smallest.
	int left = 2*index;
	int right = 2*index + 1;
	int smallest = index;

	//check if the left child is smaller than the smallest
	if(left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key){
		smallest = left;
	}
	//same thing but for the right child
	if(right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key){
		smallest = right;
	}
	//we finally want to check if the smallest is in the index position. 
	//if it isn't we swap them. We'll recursively call MinHeapify to fix the subtrees as well.
	if(smallest!=index){
	std::swap(pHeap->H[index], pHeap->H[smallest]);//swap positions in the heap
	V[pHeap->H[index]]->pos = index; //update the position in V
	V[pHeap->H[smallest]]->pos= smallest; // updates smallest position in V
	
	//recursive call to MinHeapify, fixes subtrees
	MinHeapify(pHeap, V, smallest);
	}

}
void BuildHeap(HEAP* pHeap, ELEMENT** V, int n ){
	
	printf("Instruction: BuildHeap\n");
	pHeap->size = n;//set the size of pHeap to the capacity
				      //
	//set the heap index positions to the positions of the element in V
	for(int i = 1; i<= n; i++){
		
		V[i]->pos = i;
		pHeap->H[i] = i;
	}
	//apply minHeapify from bottom up, so that the bottom nodes satisfy the heap
	//we do bottom up instead of top down so that there is less swaps, allowing the 
	//heap to be sorted faster
	for(int i = n/2; i >=1; i--){
		MinHeapify(pHeap, V, i);
	}
}

void Insert(HEAP* pHeap, ELEMENT** V, int index){
	printf("Instruction: Insert %d\n", index);
	//check and see if the index is in bounds
	if(index < 1 || index > pHeap->capacity){
		fprintf(stderr, "Error: index out of bound\n");
		return;
	}

	//check if the value is already in the heap
	if(V[index]->pos!=0){
		fprintf(stderr, "Error: V[%d] already in the heap\n", index);
		return;
	}

	//increase the size of the heap, and insert the element at the last position
	pHeap->size++;
	//instert the element into the list at the last position in pHeap
	pHeap->H[pHeap->size] = index;
	//update the elements position in V
	V[index]->pos = pHeap->size;

	//we need to fix the heap is it is violated, so we swap the element with the parent if necessary
	//we can't use minHeapify here, as minHeapify works top-down, and we need to work bottom up.
	int i = pHeap->size;
	while(i>1 &&V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key){
		std::swap(pHeap->H[i],pHeap->H[i/2]);

		//updating positions in V
		V[pHeap->H[i]]->pos = i;
		V[pHeap->H[i/2]]->pos = i/2;

		//move up to the parent, and if necessary run the while loop again
		i = i/2;
	}
	printf("Element V[%d] inserted into the heap\n", index);
}
ELEMENT* ExtractMin(HEAP* pHeap, ELEMENT** V){

	printf("Instruction: ExtractMin\n");

	if(!pHeap){
		printf("Error: heap is NULL\n");
		return nullptr;
	}
	if(pHeap->size ==0){
		printf("Error: Heap is empty\n");
		return nullptr;
	}
	int mindex = pHeap->H[1];//the minimum element is the root in a minHeap
	ELEMENT* elemin = V[mindex];
	V[mindex]->pos = 0;
	//replce the root with the last element in the heap, to maintain the structure of the tree.
	//we also run Minheapify here, since we want to work top down, and move the replaced 
	//element to the right place.
	if(pHeap->size > 1){
	pHeap->H[1] = pHeap->H[pHeap->size];
	V[pHeap->H[1]]->pos = 1;
	}
	//reduce heap size
	pHeap->size--;

	//restore heap property if necessary
	if(pHeap->size > 0){
		MinHeapify(pHeap, V, 1);
	}
	//return extracted element
	return elemin;
}

void DecreaseKey(HEAP* pHeap, ELEMENT** V, int index, double newKey){

	//print instruction
	printf("Instruction: DecreaseKey %d %lf\n", index, newKey);

	//we need to check if the index is out of range
	if(index < 1 || index > pHeap->capacity || newKey >= V[index]->key){
		fprintf(stderr, "Error: invalid call to DecreaseKey\n");
		return;
	}
	//check if the key is in the heap
	if(V[index]->pos == 0){
	fprintf(stderr, "Error: V[%d] not in the heap\n", index);
	return;
	}
	//update the key
	V[index]->key = newKey;
	int i = V[index]->pos;//get the position of the element, so that we can fix the position and maintain heap property
	
	while(i >1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key){
		std::swap(pHeap->H[i],pHeap->H[i/2]);

		//update positions 
		V[pHeap->H[i]]->pos = i;
		V[pHeap->H[i/2]]->pos = i/2;

		i = i/2;//moves us to the parent
	}
}






