#include <iostream>
using namespace std;

const int MAX = 10000;
int Queue[MAX];
int front, rear, lenQ;

/*
void QueueInit();		//khởi tạo Queue trước khi dùng
void QueuePush(int v);  //kiểm tra Queue có full trước khi gọi: if (lenQ == MAX) then FULL
int QueuePop();		//kiểm tra Quere rỗng trước khi gọi: if (lenQ == 0) then EMPTY
*/

void QueueInit()
{
	front = 0; rear = MAX - 1; lenQ = 0;
}

void QueuePush(int v)
{
	rear = (rear + 1) % MAX;
	Queue[rear] = v;
	lenQ++;
}

int QueuePop()
{
	int p = Queue[front];
	front = (front + 1) % MAX;
	lenQ--;
	return p;
}

int main()
{
	QueueInit();

	// Do something to test
	QueuePush(10);
	QueuePush(250);
	cout << Queue[front];
	QueuePush(265);
	cout << QueuePop();
	cout << QueuePop();
	cout << QueuePop();
}
