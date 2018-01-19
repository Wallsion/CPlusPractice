// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::deque;
using std::stack;
using std::queue;
using std::priority_queue;
using std::iostream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::fstream;
int power2(int r)
{
	if (r == 0)
		return 1;
	if (r % 2 == 1)//if (r & 1)
		return (int)pow(power2(r / 2), 2) * 2;//return sqr(power(r >> 2)) << 1;
	else 
		return (int)pow(power2(r / 2), 2);//return sqr(power(r >> 2))
}
int arrsum(int *arr, int begin, int end)
{
	if (begin == end)
		return arr[begin];
	int center = (begin + end) >> 1;
	return arrsum(arr,begin, center) + arrsum(arr,center + 1, end);
}
int fibonacci(int n)
{
	if (n == 1 || n == 0)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibbonaccilinear(int n, int &prev)//线性递归
{
	if (n == 0)
	{
		prev = 1;
		return 0;
	}
	else
	{
		int prevprev;
		prev = fibbonaccilinear(n - 1, prevprev);
		return prev + prevprev;
	}
}
class AA
{
public:
	AA(): a(1), b(2), p(&a) {};//构造函数初始化内部数据方式！！！！！！！(初始化列表)
private:
	int a;
	int b;
	int *p;
};
void printvalues( int(&arr)[3])
{
	for (int i = 0; i < 3; i++)
		cout << arr[i];
};
char &get_val(string &s, size_t ix)
{
	return s[ix];
}
int rgcd(int a, int b)
{
	if (b != 0)
		return	rgcd(b, a%b); 
	return a;
}
int main()
{
	/*int arr[8] = { 1,2,3,4,5,6,7,8 };
	std::cout << power2(20) << std::endl;
	std::cout << arrsum(arr, 0, 7) << std::endl;
	std::cout << fibonacci(5) << std::endl;*/

	/***************************************/
	 /*string 单个字符处理，在cctype头文件中*/
	/***************************************/
	/*string s1;
	string s2 = "abc";
	std::getline(cin, s1);
	if (s1.empty() || s1.size() == 0)
		cout << "字符串为空！";
	else
		cout << s1 << endl;
	cout << (char)toupper(s2[1]) << s2 << endl;*/
	/*vector 用法*/
	int a[3] = { 1,2,3 };
	vector<int> arr1;
	vector<int> arr2(arr1);
	vector<int> arr3(10, 1);
	vector<int> arr4(10);
	vector<int> arr5(a, a + 3);//用数组初始化vector
	cout << arr5.capacity() << arr5.size();
	arr4.push_back(1);
	cout << arr1.capacity() <<" " << arr2.size() << " " << arr3.max_size() << " " << arr4.capacity() << " " << arr4.size() << endl;
	for (vector<int>::size_type i = 0; i != 10; i++)
		arr1.push_back((const int)i);
	vector<int>::iterator iter;//
	vector<int>::const_iterator c_iter;//此迭代器只能读取值不能更改
	iter = arr1.begin();
	for (iter; iter != arr1.end(); ++iter)
		*iter = 0;
	iter.operator--();
	cout << *iter << endl;
	const int *p1;//不可以通过*p1来修改对象，但是指针可以指向const对象或者非const，但是不能同过*p1修改其指向对象的值  自以为指向const指针
	int pa = 1;
	const int pb = 2;
	p1 = &pa;
	p1 = &pb;
	const void *p2 = &pa;//void 同样需要const
	int *const p3 = &pa;//指针是const,但是其指向的对象任意类型，即指针不能被改变，指向的对象任意。
	const int *const p4 = &pb;//指针和指向的对象均为const,指针不能被改变，指向的对象也不能通过*p4更改。
	int arr2dim[][2] = { 1,2,3,4 };
	int(*pArr)[2] = &arr2dim[1];
	cout << pArr[-1][1] << endl;
	cout << sizeof(a) << sizeof(p1) << endl; 
	AA aclass;
	string str("");
	cout << sizeof(AA) << " " << sizeof(aclass) << " " << str.length() << sizeof(str);
	int *parray = a;
	cout << endl;
	string s(10, '9');
	int *pint = new int(1024);
	cout << s << *pint;
	//强制类型转换,dynamic_cast,const_cast,static_cast,reinterpret_cast。
	/*using std::runtime_error;
	using std::exception;
	throw runtime_error("别激动这只是个测试！");
	throw exception("别激动这只是个测试！");*/
		/*
	try
	{

	}
	catch (const std::runtime_error)
	{

	}*/
#ifndef NDEBUG
	std::cerr << "starting !" <<__TIME__<<__FILE__ << __LINE__ << __DATE__;
	_ASSERT(1);

#endif
	//指向指针的引用 int *&v1;
	printvalues(a);
	get_val(s, 0) = '1';//函数返回引用，不能指向局部变量。
	cout << endl << s;
	cout << endl << rgcd(100, 50);
	//函数名后面加const 表明此函数为常量成员函数，不能更改对象成员函数
	//函数重载中当形参是引用或者指针时，const和非const才是不同的类型
/* 缓冲区刷新 */
	cout << "王鑫" << endl;
	cout << "wang" << std::ends;
	cout << "xin" << std::flush;
	cout << std::unitbuf << "hello world" << "你好世界" << std::nounitbuf;
	string filename("mycplus.txt");
	ofstream ofile(filename.c_str());
	ofile << "要包含fstream头文件";
	ofile.close();
	fstream file;
	file.open(filename.c_str(),std::ios::app | fstream::out);
	file << " 即：#include <fstream>";
	file.close();
	ifstream file1("mycplus.txt", ifstream::in);
	char aa[20] = { 0 };
	file1.getline(aa,10);
	//file1.clear();
	file1.getline(&aa[9], 6);
	using std::getline;
	getline(file1,s);
	cout << s << endl;
	char *words[] = { "12","34","56","78", };
	cout << sizeof(words) / sizeof(char*) << endl;
	vector<int>::iterator iter1;
	vector<int> intvector(10, 1);
	iter1 = intvector.begin() + intvector.size() / 2;
	list<int> intlist(intvector.begin(), intvector.end());
	vector< string > stringvector(3,"test");
	stringvector.push_back("over");
	cout << intlist.front() << endl;
	intlist.insert(intlist.begin(), 100);
	cout << intlist.front() << endl;
	intlist.pop_front();
	cout << intlist.front() << endl;
	stringvector.insert(stringvector.begin(), "wang");

	vector< string >::iterator itstrvector = stringvector.begin();
	cout << stringvector[0] << *itstrvector << *(itstrvector + 1) << endl;
	//容器可以进行比较，类型要相同
	if (!stringvector.empty())
	{
		vector< string >::reference refer1 = *stringvector.begin();
		vector< string >::reference refer2 = stringvector.front();
		vector< string >::reference refer3 = *--stringvector.end();
		vector< string >::reference refer4 = stringvector.back();
		cout << refer1 << " " << refer2 << " " << refer3 << " " << refer4 << endl;
		stringvector.erase(--stringvector.end());
		cout << stringvector.back() << endl;

	}
	deque< int > intdeque1(5, 0);
	deque< int > intdeque2(5, 1);
	intdeque1.insert(intdeque1.begin(), 1);
	cout << intdeque1.front() << intdeque2.front() << endl;
	intdeque1.swap(intdeque2);
	cout << intdeque1.front() << intdeque2.front() << endl;
	intdeque1.assign(5, 100);
	cout << intdeque1.front() << endl;
	intdeque1.assign(intdeque2.begin(), intdeque2.end());
	cout << intdeque1.front() << endl;
	const char *pchar = "wangxin";
	string str1(pchar,0,7);
	string str2(str1, 4, 3);
	str2.insert(0, str1, 4, 3);
	cout << str1 << " " << str2 << " " << str1.front() << endl;
	str1.erase(1, 3);
	cout << str1 << endl;
	string::iterator striter = str2.begin();
	while (striter != str2.end())
	{
		cout << *striter++ << endl;
	}
	str2 = str2.substr(0, 4);
	string str3("daihuijun");
	str3.insert(str3.begin(), str2.begin(), str2.end());
	cout << str2 << " " << str3 << endl;
	str3.replace(0, 4, "wangxin ");
	cout << str3 << endl;
	cout << str3.find("xin") << endl;
	cout << str3.find_first_of("xin") << endl;
	cout << str3.find_last_of("xin") << endl;
	//find(c类型起始下表或者string类型,索引开始位置，c查找个数);
	const char *pchar1 = "这只是个测试！";
	string str4("这只是个测试！");
	cout << str4.compare(pchar1) << endl;
	priority_queue <int, vector<int> ,std::greater<int> > priqueue;
	priqueue.push(5);
	priqueue.push(1);
	priqueue.push(3);
	priqueue.push(6);
	while (!priqueue.empty())
	{
		cout << priqueue.top() << endl;
		priqueue.pop();
	}
    return 0;
	
}

