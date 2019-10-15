#include <iostream>

// (a + b) mod P
int AddMod(int a, int b, int P)
{
	a = a % P;
	b = b % P;
	int tmp = P - a;
	if (tmp > b) return a + b;
	return b - tmp;
}

// a*b mod P
int MulMod(int a, int b, int P)
{
	if (a == 1) return b % P;
	if (b == 1) return a % P;
	if (a > b)
	{
		int tmp = a; a = b; b = tmp;
	}
	int c = MulMod(a/2, b, P);
	c = AddMod(c, c, P);
	if (a % 2 == 0) return c;
	else return AddMod(c, b, P);
}

// a ^ b mod P
int XmuN(int X, int N, int P)
{
	if (N == 1) return X % P;
	int a = XmuN(X, N/2, P);
	a = MulMod(a, a, P);
	if (N % 2 == 0) return a;
	else return MulMod(a, X, P);
}

int main()
{
	int X, N, P = 1000000007;
	std::cin >> X >> N;
	std::cout << XmuN(X, N, P);
}