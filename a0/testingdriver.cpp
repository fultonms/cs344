#include <iostream>
#include <assert.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void recminmax(int [], int, int&, int&, int &);
int iterminmax(int[], int);

using namespace std;

int main(){
	int len, Icount, Rcount;
	int min, max;
	
	srand (time(NULL));

	ofstream out;
	out.open("out.dat");
	
	for(int i=1; i<1000; i++){
		int array[i];
		len=i;
		Rcount=0;

		for(int j=0; j<len; j++){
			array[j]=rand();
		}

		Icount=iterminmax(array, len);
		recminmax(array, len, min, max, Rcount);
		out<<Icount<<"	"<<Rcount<<endl;;
	}

	out.close();
		
	return 0;
		
}

int iterminmax(int numbers[], int len){

        int max=numbers[0];
        int min=numbers[0];
        int count=0;

        if(len==1){
                max=numbers[0];
                min=numbers[0];
                return 0;
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
                return 1;
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
	return count;
}


void recminmax(int input[], int len, int & min, int & max, int & count){

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

        recminmax(input, leftlen, leftmin, leftmax, count);

        int rightmin, rightmax;
        int rightlen= len-leftlen;
        int temp[rightlen];

        //Initializing the new array.
        for(int i=0; i <rightlen; i++){
                temp[i]=input[leftlen+i];
        }

        recminmax(temp, rightlen, rightmin, rightmax, count);

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

