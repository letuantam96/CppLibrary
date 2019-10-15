#include <iostream>
#define MAX 10000
using namespace std;

int A[10] = {1,9,8,7,5,6,3,2,4,15};

bool QuickSort(int *A, int L, int H)
{
	int i, j, pivot;
	if (L >= H) return 1;
	pivot = A[(int)((L+H)/2)];
	i = L; j = H;
	do
	{
		while (A[i] < pivot) i++;
		while (A[j] > pivot) j--;
		if (i <= j)
		{
			if (i < j)
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	QuickSort(A, L, j); QuickSort(A, i, H);
	return 1;
}

int main()
{
	QuickSort(A, 0, 9);
}