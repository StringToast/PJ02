#include "util.h"
#include <iomanip>//to ensure we print floating point values to pass the test
void Read(const char* filename, HEAP*& pHeap, ELEMENT**& V){

//output instruction
cout << "Instruction: Read" <<endl;


//open file in read mode
ifstream inputFile(filename);
//error checking to see if the file opens
if(!inputFile.is_open()){
	cerr<<"Error: cannot open file "<<filename<<endl;
	return;//exit if the file cannot be opened
	}
//we now read the Number of elements to tell us how big we need V to be.
int n;
if(!(inputFile >> n)){
cerr<<"Error: Invalid File Format, expected number of elements"<<endl;
	exit(1);
}


//allocate pHeap
pHeap = new HEAP;
pHeap->capacity = n;
pHeap->size = 0;
pHeap->H = new int[n+1];

//initialize all elements at V to nullptr, we overwrite this later
V = new ELEMENT*[n+1];
for(int i = 0; i <=n; i++){
	V[i] = nullptr;
}	
//read the elements of the input file into V
for( int i = 1; i <= n; i++){
	double key;
	inputFile >> key; //read in key to key value
	
	V[i] = new ELEMENT;
	//check to see if the allocation succeeded
	if(!V[i]){
		cerr<<"Error: Memory allocation failed for V["<<i<<"]"<<endl;
		exit(1);
	}
	V[i] -> index = i;
	V[i] -> key = key;
	V[i]->pos = 0;//set to zero because we haven't written it to the heap yet

	}	
	//close the input file
	inputFile.close();
}

//Write function, writes the elements to an output file in the format "index, key, pos"
void Write(const char* filename, ELEMENT** V, int capacity){

//cout the instruction
cout << "Instruction: Write"<<endl;

// open the output file in write mode
ofstream outputFile(filename);
	//check if the file can be opened. if it cannot then exit early.
	if(!outputFile.is_open()){
		cerr<< "Error: Cannot open file " <<filename<<endl;
		return;
	}
//write the array contents to the file, formatting it in "index, key, pos"
	outputFile<<fixed<<setprecision(6);
	for(int i = 1; i <= capacity; i++){
		outputFile << V[i]->index<<" "<<V[i]->key<<" "<<V[i]->pos<<endl;
	}
//close file
outputFile.close();	

}
//print the array contents of V
void printArray(ELEMENT** V, int capacity){
//print the instruction
cout<<"Instruction: PrintArray"<<endl;

//error checking for V, seeing if it is null
if(!V){
	cerr<<"ERROR: array is NULL"<<endl;
	return;
	}
//print the array elements, similar to write but just in stdout
cout << fixed << setprecision(6); // not sure why but the program won't print the keys as floats, this is the fix
for(int i = 1; i<=capacity; i++){
	if(!V[i]){
	cerr << "Error: V[" << i <<"] is NULL" <<endl;
	}
	cout<< V[i]->index << " "
	<< V[i]->key <<" "
	<< V[i]->pos <<endl;
	}
}
void printHeap(HEAP* pHeap ){
//print the instructions
cout<<"Instruction: PrintHeap"<<endl;

//check if pHeap is null, if not we print it in format
if(pHeap == nullptr){
	cerr<<"ERROR: heap is NULL"<<endl;
	}
//here we say the current state of the heap, its capacity and its size
cout<<"Capacity = "<<pHeap->capacity<<", size = "<<pHeap->size<<endl;
cout << fixed <<setprecision(6);
for(int i = 1; i<=pHeap->size; i++){
	cout<<"H["<<i<<"] = "<<pHeap->H[i]<<endl;
	}
}





