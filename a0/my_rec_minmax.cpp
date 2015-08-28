/*
Author: Michael Fulton
Date: 2/2/15
*/

#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

void minmax(int [], int, int &, int &, int &);

int main(int argc, char * args[]){
	
	//File I/O Setup.
	ifstream in;
	in.open(args[1]);
	
	int length;	
	
	in >> length;

	int input[length];
	
	//Read in the array.
	for(int i=0; i< length; i++){
		in >> input[i];
	}

	
	int count = 0;
	int min=0;
	int max=0;

	//Compute min and max, then print out.
	minmax(input, length, min, max, count);
	cout<<length<<" "<<min<<" "<<max<<" "<<count<<endl;

	in.close();


}

void minmax(int input[], int len, int & min, int & max, int & count){

	//Make sure the array is not empty.
	assert(len >0);
	
	//If it's an array with one element, it's both the min and max.
	if(len == 1){
		max=min=input[0];
		return;
	}

	//If the array has two elements, do a simple comparison.
	else if(len == 2){
		count ++; 
		if(input[0] >input[1]){
			max= input[0];
			min = input[1];
		}
		else{
			max=input[1];
			min=input[0];
		}
		return;
	}
	
	//Otherwise, split the array into two halves, and compute minmax on them.
	int leftmin, leftmax;
	int leftlen = len/2;

	minmax(input, leftlen, leftmin, leftmax, count);

	int rightmin, rightmax;
	int rightlen= len-leftlen;
	int temp[rightlen];

	//Initializing the new array.
	for(int i=0; i <rightlen; i++){
		temp[i]=input[leftlen+i];
	}

	minmax(temp, rightlen, rightmin, rightmax, count);

	count++;

	//Reconcile the min and maxes from the two different halves.
	if(leftmin < rightmin){
		min = leftmin;
	}
	else{
		min = rightmin;
	}

	count++;
	if(leftmax >rightmax){
		max=leftmax;
	}
	else{
		max=rightmax;
	}

}
