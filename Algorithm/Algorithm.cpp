// Algorithm.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Quenue.h"
#include "List.h"
#include "my_Vector.h"
//using namespace std;
int main()
{
	quenue Q;
	Q.Qcreate(10);
	Q.Qin(1);
	Q.Qin(2);
	std::cout << Q.Q_intout() << std::endl;
	//Sleep(3000);
	float c = 3.0;
	std::cout << std::hex << c << "\n";
	/*
	//my_Vector<int> vetor;
	int  a[5] = { 1,2,3,4,5 };
	my_Vector<int> vetor(a,0,5);
	std::cout << vetor.size() << vetor.empty();
	*/
	enum MyEnum
	{
		num1 = 1,
		num2,
		num3
	};
	MyEnum x = (MyEnum)0;
	std::cout << x;
    return 0;
}

