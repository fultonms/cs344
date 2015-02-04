#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

void minmax(int [], int, int &, int &, int &);

int main(int argc, char * args[]){
	
	ifstream in;
	in.open(args[1]);
	
	int length;	
	
	in >> length;

	int input[length];

	for(int i=0; i< length; i++){
		in >> input[i];
	}

	
	int count = 0;
	int min=0;
	int max=0;

	minmax(input, length, min, max, count);

	cout<<"The max is: "<<max<<"."<<endl;
	cout<<"The min is: "<<min<<"."<<endl;
	cout<<"The number of count operations is: "<<count<<"."<<endl;

	in.close();


}

void minmax(int input[], int len, int & min, int & max, int & count){

	assert(len >0);
	
	if(len == 1){
		max=min=input[0];
		return;
	}
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
	
	int leftmin, leftmax;
	int leftlen = len/2;

	minmax(input, leftlen, leftmin, leftmax, count);

	int rightmin, rightmax;
	int rightlen= len-leftlen;
	int temp[rightlen];

	for(int i=0; i <rightlen; i++){
		temp[i]=input[leftlen+i];
	}

	minmax(temp, rightlen, rightmin, rightmax, count);

	count++;
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
