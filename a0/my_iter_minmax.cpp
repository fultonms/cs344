#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void minmax(int[], int);

int main(int argc, char * args[]){
	
	ifstream in;
	in.open(args[1]);
	
	int length;	
	
	in >> length;
	cout <<length<<endl;

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
