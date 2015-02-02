#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void minmax(int, int [], int, int &, int &, int &);

int main(int argc, char * args[]){
	
	ifstream in;
	in.open(args[1]);
	
	int length;	
	
	in >> length;

	int input[length];

	for(int i=0; i< length; i++){
		in >> input[i];
	}
	
	int min=input[0];
	int max=input[0];
	int count = 0;
	minmax(1, input, length, min, max, count);
	
	cout<<"The max is: "<<max<<"."<<endl;
	cout<<"The min is: "<<min<<"."<<endl;
	cout<<"The number of count operations is: "<<count<<"."<<endl;

	in.close();


}

void minmax(int i, int numbers[], int len, int & min, int & max, int & count){

	if(i==len)
		return;
	else{
		count++;
		if(numbers[i] > max){
			max=numbers[i];
		}
		else{
			count ++;
			if(numbers[i]< min){
				min=numbers[i];
			}

		}

	}
	i++;
	minmax(i, numbers, len, min, max, count);
	return;
}



