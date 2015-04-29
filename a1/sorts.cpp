#include <iostream>
#define swap(a,b) ((a)^=(b), (b)^=(a), (a)^=(b))

using namespace std;

void mergesort(int [], const int, const int);
void merge(int[], int, int, int);

void quicksort(int [] , int, int, int(*choose_pivot)(int [], int));
int part(int [], int, int, int(*choose_pivot)(int [] , int));

extern int cost;

void bsort(int array[], int size){
	bool swapped;
	while(swapped){
		swapped = false;
		for(int i = 0; i<size; i++){
			cost++;
			if(array[i-1] > array[i]){
				swap(array[i-1], array[i]);
				swapped = true;
			}
		}	
	}
}

void isort(int array[], int size){
	int j;
	for(int i=0; i<size; i++){
		j=i;	
		while(j > 0 && array[j-1] > array[j]){
			cost++;
			swap(array[j], array[j-1]);
			j--;
		}
	}
}

void ssort(int array[], int size){
	int i, j;
	int min;
	
	for(i = 0; i<size; i++){
		min= i;
		for(j = i+1; j<size; j++){
			cost++;
			if(array[j] < array[min]){
				min = j;	
			}
		}

	if(min != i)
		swap(array[i], array[min]);
	}	
}

void msort(int array[], int size){
	mergesort(array, 0, size-1);
}

void merge(int array[], const int begin, const int mid, const int end)
{
	// Variables declaration. 
	int * b= new int[end+1-begin];
	int h,i,j,k;
	h=begin;
	i=0;
	j=mid+1;
	// Merges the two array's into b[] until the first one is finish
	while((h<=mid)&&(j<=end))
	{
		cost++;
		if(array[h]<=array[j])
		{
			b[i]=array[h];
			h++;
		}
		else
		{
			b[i]=array[j];
			j++;
		}
		i++;
	}
	// Completes the array filling in it the missing values
	if(h>mid)
	{
		for(k=j;k<=end;k++)
		{
			b[i]=array[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=array[k];
			i++;
		}
	}

	for(k=0;k<=end-begin;k++) 
	{
		array[k+begin]=b[k];
	}
	delete[] b;
}
 
void mergesort( int array[], const int begin,  const int end )
{
	int mid;
	if( begin < end )
	{
		mid = ( begin + end ) / 2;
		mergesort( array, begin, mid );
		mergesort( array, mid + 1, end );
		merge( array, begin, mid, end );
	}
}

void my_qsort(int array[], int size, int (*choose_pivot)(int [], int)){
	quicksort(array, 1, size, (*choose_pivot));
//	for(int i=0; i<size; i++)
//		cerr<<array[i]<<" ";
//	cerr<<endl;
}

void quicksort(int array[], int low, int high, int(*choose_pivot)(int [], int)){
	if(low < high){
		int p = part(array, low, high, (*choose_pivot));
		quicksort(array, low, p-1, (*choose_pivot));
		quicksort(array, p+1 , high, (*choose_pivot));	
	}
}

int part(int array[], int low, int high, int(*choose_pivot)(int [], int)){
	int pivot = (*choose_pivot)(array, (high- low));
	int pivotValue = array[pivot];

	swap(array[pivot], array[high]);
	int storeIndex = low;
	for(int i=low; i<=high-1; i++){
		if(array[i] <= pivotValue){
			swap(array[i], array[storeIndex]);
			storeIndex++;
		}
	}
	swap(array[storeIndex], array[high]);
	return storeIndex;
}

// median finder
void select(int array[], int size, int K, int &answer){
	
}

