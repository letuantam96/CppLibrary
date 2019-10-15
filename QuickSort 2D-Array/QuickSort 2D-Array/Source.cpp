/*
Hàm QuickSort2D(A, L, H) sắp xếp mảng 2 chiều A[2][N] từ phần tử L tới phần tử H
theo thứ tự ưu tiên: sắp xếp hàng trên trước, nếu các phần tử hàng trên = nhau thì sắp xếp theo
các phần tử hàng dưới
*/
#include <iostream>
#define MAX 10000
using namespace std;

int Compare2D(int A1, int A2, int B1, int B2)
{
	if (A1 < B1) return -1;
	if (A1 > B1) return 1;
	if (A2 < B2) return -1;
	if (A2 > B2) return 1;
	return 0;
}

bool QuickSort2D(int A[][10], int L, int H)    //NHỚ thay độ dài mảng khi sử dụng
{
	int i, j, pivot;
	if (L >= H) return 1;
	pivot = (int)((L+H)/2);
	i = L; j = H;
	do
	{
		while ( Compare2D(A[0][i], A[1][i], A[0][pivot], A[1][pivot]) == -1 ) i++;
		while ( Compare2D(A[0][j], A[1][j], A[0][pivot], A[1][pivot]) == 1 ) j--;
		if (i <= j)
		{
			if (i < j)
			{
				int temp = A[0][i];
				A[0][i] = A[0][j];
				A[0][j] = temp;
				temp = A[1][i];
				A[1][i] = A[1][j];
				A[1][j] = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	QuickSort2D(A, L, j); QuickSort2D(A, i, H);
	return 1;
}

int A[2][10] = 
{
	{1, 9, 5, 7,  5, 6, 3, 2, 7, 15},
	{8, 5, 4, 9, 12, 9, 7, 5, 6,  2}
};
int main()
{
	QuickSort2D(A, 0, 9);
}