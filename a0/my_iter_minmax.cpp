/*
AUTHOR: Michael Fulton
DATE: 2/2/15
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void minmax(int[], int);

int main(int argc, char * args[]){
	
	//File I/O setup.
	ifstream in;
	in.open(args[1]);
	

	//Read in number of numbers we're using.
	int length;		
	in >> length;
	cout <<length<<endl;


	//Read in actual numbers.
	int input[length];
	for(int i=0; i< length; i++){
		in >> input[i];
	}

	minmax(input, length);
	

	in.close();


}

void minmax(int numbers[], int len){

	int max=numbers[0];
	int min=numbers[0];
	int count=0;

	if(len==1){
		max=numbers[0];
		min=numbers[0];
		return;
	}
	else if(len==2){
		if(numbers[0] > numbers[1]){
			max= numbers[0];
			min= numbers[1];
		}
		else{
			max= numbers[1];
			min= numbers[0];
		}
		return;
	}

	//If the current number is bigger than the max, make it the new max.  
	//If it isn't, see if it's smaller than the min.  If it is, it's the new min.
	//Since we don't test min until we know it's not max, we CAN save cost operations.
	//This algorithm's worst case is 2N-2.
	for(int i=1; i < len; i++){
		count++;
		if(numbers[i] > max){
			max = numbers[i];
		}	
		else {
			count++;
			if(numbers[i] < min){
				min = numbers[i];
			}	
		}
		
	}

	cout<<"The max is: "<<max<<"."<<endl;
	cout<<"The min is: "<<min<<"."<<endl;
	cout<<"The number of array element comparisons is: "<<count<<"."<<endl;
}
