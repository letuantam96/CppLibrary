#include <iostream>
using namespace std;

/*
	cú pháp: BinarySearch(A, X, s, e)
	trả về chỉ số của phần tử = X trong mảng A đã sắp xếp, xét từ phần tử bắt đầu s, kết thúc e
	nếu không tìm thấy thì trả về -1
*/

int BinarySearch(int *A, int X, int s, int e)
{
	int inf, sup, median;
	inf = s; sup = e;
	while (inf <= sup)
	{
		median = (inf + sup) / 2;
		if (A[median] == X) return median;
		if (A[median] < X) inf = median + 1;
		else sup = median - 1;
	}
	return -1;
}

int A[10] = {1,3,4,8,9,11,15,19,23,50};

int main()
{
	cout << BinarySearch(A, 20, 0, 9) << endl;
	cout << BinarySearch(A, 11, 0, 9) << endl;
}