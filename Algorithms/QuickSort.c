
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**Algo

algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p - 1)
        quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo-1        // place for swapping
    for j := lo to hi - 1 do
        if A[j] ≤ pivot then
            i := i + 1
            swap A[i] with A[j]
    swap A[i+1] with A[hi]
    return i+1

*/



/**Function for Quick Sort **/





int partition (int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);
    int j=0;
	for (j = l; j <= h- 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap (&arr[i], &arr[j]);
		}
	}
	swap (&arr[i + 1], &arr[h]);
	return (i + 1);
}


void quicksort(int *arr,int p,int q){
    int r;
    if(p<q){
            r=partition(arr,p,q);
            quicksort(arr,p,r-1);
            quicksort(arr,r+1,q);
    }


}
