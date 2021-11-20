#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// swapping variables
void swap(int*a,int*b)
{
 int temp =*a;
 *a=*b;
 *b=temp ;
}
//quick sorting
// divide array into 2 parts 1: left side of the pivot , smaller than it || 2: right side of the pivot , bigger than it
int dividing(int arr[],int lowest,int highest)
{
    int i = lowest -1 ;        	    	// variable used to refer to each index to the left of the pivot
    int pivot = arr[highest]; 		   // the pivot at the right most index  to which all the numbers will be compared
    int j ;
	for( j=lowest;j<highest;j++)
    {
        if(arr[j]<pivot)
        {
            i++ ; // increase 1 to i to move to the next index
            swap(&arr[i],&arr[j]) ;
        }
    }
	swap(&arr[i+1],&arr[highest]) ;
	return i+1 ; // "i+1" is the index of the pivot after quick sorting
}
int quick_sort(int arr[],int lowest , int highest) // quick sorting algorithim
{
    if (lowest<highest)
    {
	int new_pivot=dividing(arr,lowest,highest);    //another pivot for the 2  parts that is smaller,bigger than the first pivot
	quick_sort(arr,lowest,new_pivot-1); 	   	  //the new pivot for the part that was on the left
	quick_sort(arr,new_pivot+1,highest);		 //the new pivot for the part that was on the right
    }
}

// insertion sorting
void insertion_sort(int arr[],int lowest ,int  highest)
{
    for (int j=0;j<highest;j++)
        {
            for(int z=j+1;z>0;z--)
            {
                if (arr[z]<arr[z-1])
                    {
                    swap(&arr[z],&arr[z-1]);
                    }
            }
        }
}

int main()
{
	int arr[100000] ;
	int idx;
	for(idx=0;idx<100000;idx++) //filling array with random numbers
	{
		 arr[idx]=rand();
	}
  int n ;
  n=sizeof(arr)/arr[0] ;
  quick_sort(arr,0,n-1) ;//sorting arraay using quick sort
  int time_quick_sort=clock();
  printf("quick _sorting time is : %f\n",(float)time_quick_sort / CLOCKS_PER_SEC); //measuring time

  int arr2[100000];
  int location ;
  for (location=0;location<100000;location++)
    {
        arr2[location]=rand(); // filling second array with random numbers
    }
  int size ;
  size=sizeof(arr2)/arr2[0];
 insertion_sort(arr2,0,size-1);// sorting array using insertion sort
 int time_insertion_sort=clock();
  printf("insertion _sorting time is : %f",(float)time_insertion_sort / CLOCKS_PER_SEC); //measuring time
}
