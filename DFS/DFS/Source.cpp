/*
Hàm DFS(A, N, s, Trace):
Input:
	A[][]: bool: ma trận lưu đồ thị ( A[i][j] = 1 nếu có đường đi từ i tới j, = 0 nếu không có)
	N: int: số đỉnh của đồ thị: từ 1..N
	s: int: vị trí bắt đầu
Output:
	Trace[]: mảng lưu vết đánh dấu đường đi tới các đỉnh
			 Trace[i] lưu giá trị đỉnh cha của đỉnh i, = 0 nếu không có đường đi từ s, Trace[s] = -1
*/

#include <iostream>
#define MAX 10000
using namespace std;

// Before call, sửa giá trị cột ma trận A và KHỞI TẠO MẢNG Trace[]: for (int i = 1; i <= N; i++) Trace[i] = 0; Trace[s] = -1;
void DFS(bool A[][9], int N, int u, int *Trace)
{
	int v;
	for (v = 1; v <= N; v++)
		if (A[u][v] && (Trace[v] == 0))
		{
			Trace[v] = u;
			DFS(A, N, v, Trace);
		}
}

int main()
{
	bool A[9][9];
	int Trace[MAX];
	int N = 8, s = 1;

	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
			A[i][j] = 0;
	A[1][2] = A[2][1] = A[1][3] = A[3][1] = A[2][3] = A[3][2] = A[2][4] = A[4][2] = 1;
	A[3][5] = A[5][3] = A[4][6] = A[6][4] = A[7][8] = A[8][7] = 1;

	for (int i = 1; i <= N; i++) Trace[i] = 0; Trace[s] = -1;
	DFS(A, N, s, Trace);
}