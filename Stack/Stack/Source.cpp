#include <iostream>
using namespace std;

const int MAX = 10000;
int Stack[MAX];
int top;

/*
void StackInit();		// Khởi tạo Stack rỗng trước khi dùng
void StackPush(int v);	// Kiểm tra Stack full trước khi đẩy: if (top == MAX) => FULL
int StackPop();			// Kiểm tra Stack rỗng trước khi lấy: if (top == 0) => EMPTY		
*/

void StackInit()
{
	top = 0;
}

void StackPush(int v)
{
	Stack[++top] = v;
}

int StackPop()	
{
	int p = Stack[top--];
	return p;
}

int main()
{
	StackInit();

	// Test some thing
	StackPush(10);
	StackPush(25);
	StackPush(36);
	// cout << StackPop() << StackPop(); // Gọi 2 hàm liên tiếp dẫn tới kết quả sai
	cout << StackPop();
	cout << StackPop();
}