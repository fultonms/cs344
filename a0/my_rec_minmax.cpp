#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * args[]){
	
	ifstream in;
	in.open(args[0]);
	
	int length;	
	int input;
	
	length= in.getline();
	cout <<length;

	for(int i=0; i < length; i++){
		in >> input;
		cout<<input<<" ";
	}
	cout<< endl;
	

	in.close();


}
