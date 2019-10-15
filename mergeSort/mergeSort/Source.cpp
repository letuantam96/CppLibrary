#include <iostream>
using namespace std;
#define INF 9999999

int n, c;
int A[100000];
int dL[50000];
int dR[50000];

void merge(int l, int m, int r)
{
	int i, iL = 0, iR = 0;
	for (i = 0; i <= m - l; i++) dL[i] = A[l + i]; dL[i] = INF;
	for (i = 0; i <= r - m - 1; i++) dR[i] = A[m + 1 + i]; dR[i] = INF;
	for (i = l; i <= r; i++)
		if (dL[iL] < dR[iR]) A[i] = dL[iL++];  // sap xep tang dan, doi chieu thi doi "<" thanh ">"
		else A[i] = dR[iR++];
}

void mSort(int l, int r)
{
	if (l == r) return;
	int m = (l + r) / 2;
	mSort(l, m);
	mSort(m + 1, r);
	merge(l, m, r);
}

int main()
{
	freopen("input.txt","r",stdin);
	
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> A[i];

		mSort(0, n - 1);


	return 0;
}