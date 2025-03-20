#include <iostream>
#include <string>
#include "data_structures.h"
#include "heap.h"
#include "util.h"

using namespace std;

int main(int argc, char* argv[]){

	//correct argument check
	if(argc != 3){
		cerr<<"Usage: ./PJ2 <I-File> <O-File>"<<endl;
		return 1;
	}

	//initialize heap and array
	HEAP* pHeap = nullptr;
	ELEMENT** V = nullptr;


	string command;
	//process the commands, similarly to PJ1 but we handle the errors within function instead of in main
	while(cin >> command){
		
		if(command == "Stop"){
			cout<<"Instruction: Stop"<<endl;
			break;
		}
		else if(command == "Read"){
			Read(argv[1], pHeap, V);
		}
		else if(command == "PrintArray"){
			printArray(V, pHeap->capacity);
		}
		else if(command == "PrintHeap"){
			printHeap(pHeap);	
		}else if(command == "BuildHeap"){
			BuildHeap(pHeap, V, pHeap->capacity);
		}else if(command == "Insert"){
			
			int index;
			cin >> index;
			Insert(pHeap, V, index);

		}else if(command =="ExtractMin"){
			ExtractMin(pHeap, V);
		  
		}else if(command == "DecreaseKey"){
			int index;
		       double newKey;
	       		cin >>index>>newKey;
	 		DecreaseKey(pHeap, V, index, newKey);

		}else if(command == "Write"){
			Write(argv[2], V, pHeap->capacity);
		}else{
			cerr<<"Warning: Invalid Instruction"<<endl;
		}
		
	}

	//when we finish with commands we clean up the memory
	
	if(pHeap){
		if(pHeap->H){
		delete[] pHeap->H;
		pHeap->H = nullptr;
		}	
		if(V){
		for(int i = 1; i<=pHeap->capacity; i++){
			if(V[i]){
				delete V[i];
				V[i] = nullptr;
				}
			}
		delete[] V;
		V = nullptr;
		}
	delete pHeap;
	pHeap = nullptr;

	}
return 0;

}
