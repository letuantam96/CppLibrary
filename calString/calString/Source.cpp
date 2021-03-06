#include <iostream>
using namespace std;

/*
Hàm calString(F) tính giá trị chuỗi F có dạng "1+2+5*3+9*1+8*3*5"
*/

int calString(char *F)
{
	int S = 0;
	int T = F[0] - 48;
	for (int i = 1; F[i] != '\0' ; i += 2)
	{
		if (F[i] == '+')
		{
			S = S + T;
			T = F[i + 1] - 48;
		}
		else T = T * (F[i + 1] - 48);
	}
	S = S + T;
	return S;
}

int main()
{
	char F[] = "1+2+5*3+9*1+8*3*5";
	cout << calString(F);
}