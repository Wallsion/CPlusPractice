#include "MiGong.h"
using namespace std;
int main()
{
	MyStack<int> myStack(10);
	myStack.push(10);
	cout << myStack.getTopVlaue();
	int a[5][5] = 
	{
		0,0,0,1,0,
		1,1,0,0,0,
		0,0,0,1,1,
		0,1,1,0,1,
		0,0,0,0,0
	};
	MiGong<int> migong(a,5,5);
	migong.beginEndPos(0,0,4,4);
	migong.caculateDis();
	migong.printResult();
	return 1;
}
