#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * args[]){
	
	ifstream in;
	in.open(args[1]);
	
	int length;	
	
	in >> length;

	int input[length];

	for(int i=0; i< length; i++){
		in >> input[i];
	}
	


	in.close();


}
