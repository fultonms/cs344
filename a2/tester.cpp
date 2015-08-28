#include<iostream>
#include<cstdlib>
#include "bst.h"
#include "splay.h"

using namespace std;

void shuffle(int[], int);

int main(int argc, char *argv[]){
	if(argc < 1)
		exit(1);
	
	int total_size = atoi(argv[1]);

	for(int i=1; i<total_size; i++){
		BST<int>* rootBST = NULL;
		Splay<int>* rootSplay = NULL;
	
		int array[i];
		for(int k=0; k<i; k++)
			array[k] =k;

		shuffle(array, i);
	
		for(int j=0; j<i; j++){
			
			if(rootBST == NULL)
				rootBST = new BST<int>(array[0]);
			else
				rootBST = rootBST->insert(array[j]);

			if(rootSplay == NULL)
				rootSplay = new Splay<int>(array[0]);
			else
				rootSplay = rootSplay->insert(array[j]);
			
		}
		rootBST->updateHeight();
		rootSplay->updateHeight();

		cout<<i<<" "<< rootBST->getHeight()<<" "<<rootSplay->getHeight()<<endl;
	
	}
}


void shuffle(int array[], int size)
{
    int index;
    srand(time(0));
    for (int i=size-1; i>0; i--) {
        index = rand() % i;
        swap(array[i], array[index]);
    }
}

