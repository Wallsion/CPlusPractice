#include <string>
#include <iostream>
#include <assert.h>
#ifndef MY_STACK_MIGONG
#define MY_STACK_MIGONG
#define WX_LEFT 0
#define WX_RIGHT 1
#define WX_UP 2
#define WX_DOWN 3
#define WX_FIRST -1
using std::string;
template <class type>
class MyStack
{
public:
	MyStack(const int temStackNum){pStackBottom = new type[temStackNum * 2];stackNum = temStackNum * 2;pStack = pStackBottom;}
	MyStack(const MyStack<type> &temStack);
	type* getBottomPtr() const {return pStackBottom;}
	int getNValue()const {return stackNum;}
	type getTopVlaue() const;
	~MyStack(){delete[] pStackBottom;}
	type pop();
	void push(type temValue);
	bool isEmpty(){if (pStack == pStackBottom) return true; else return false;}
private:
	type *pStack;
	int stackNum;
	type *pStackBottom;
};
template <class type>
MyStack<type>::MyStack(const MyStack<type> &temStack)
{
	pStackBottom = new type[temStack.getNValue()];
	memcpy(pStackBottom,temStack.getBottomPtr(),temStack.getNValue() * sizeof(type));
}
template <class type>
type  MyStack<type>::getTopVlaue() const 
{
	if (pStack != pStackBottom) 
		return *(pStack - 1);
	else
	{
		std::cout << "error!";
		return -1;
	}
}
template <class type>
type MyStack<type>::pop()
{
	type tem;
	if(pStack != pStackBottom)
	{
		--pStack;
		tem = *pStack;
	}
	else
	{
		std::cout<<"error!";
	}
	return tem;
}

template <class type>
void MyStack<type>::push(type temValue)
{
	if((pStack - pStackBottom) / sizeof(type) < stackNum - 1)
	{
		*pStack = temValue;
		++pStack;
	}
	else
	{
		std::cout<<"error!";
	}
	return;
}
class MiGongNode
{
public:
	int x;
	int y;
	int up,down,left,right;
	MiGongNode():x(-1),y(-1){};
};
template <class T>
class MiGong
{
public:
	MiGong(void *p, int row, int col);
	void beginEndPos(int xBegin, int yBegin, int xEnd, int yEnd){this->xBegin = xBegin; this->yBegin = yBegin; this->xEnd = xEnd; this->yEnd = yEnd;}
	void caculateDis();
	void printResult();
	~MiGong();
private:
	void judge(MiGongNode*, int from);
	void searchDis(MiGongNode *node, MyStack<MiGongNode> &stack, int x, int y, int from,bool &isFind);
private:
	int row,col;
	int xBegin;
	int yBegin;
	int xEnd;
	int yEnd;
	T **miGongArr;
	int *resutlArr;
	int resultNum;

};
template <class T>
MiGong<T>::MiGong(void *p, int row, int col)
{
	T *tem = (T*)p;
	miGongArr = new T*[row];
	this->row = row;
	this->col = col;
	for(int i = 0; i < row; i++)
	{
		miGongArr[i] = new T[col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			miGongArr[i][j] = *(tem + i * row + j);
		}

	}
	resutlArr = new int[(row * col) * 2];
	resultNum = 0;
}
template <class T>
MiGong<T>::~MiGong()
{
	delete[] resutlArr;
	for(int i = 0; i < row; i++)
	{
		delete[] miGongArr[i];
	}
	delete[] miGongArr;
}
template <class T>
void MiGong<T>::caculateDis()
{
	int i;
	bool isFind = false;
	MiGongNode *beginNode = new MiGongNode;
	beginNode->x = xBegin;
	beginNode->y = yBegin;
	MyStack<MiGongNode> myStack(row * col);
	MyStack<MiGongNode> &stack = myStack;
	searchDis(beginNode, stack, xBegin, yBegin, WX_FIRST, isFind);
	if(stack.isEmpty())
	{
		std::cout<< "No Access!" << endl;
	}
	else
	{
		i = 0;
		MiGongNode temNode;
		while(!stack.isEmpty())
		{
			temNode = stack.pop();
			resutlArr[i * 2] = temNode.x;
			resutlArr[i * 2 + 1] = temNode.y;
			i++;
		}
		resultNum = i;
	}
}
template <class T>
void MiGong<T>::judge(MiGongNode *node, int from)
{
	if(node->x - 1 < 0)
		node->up = 1;
	else if(miGongArr[node->x - 1][node->y] == 1)
		node->up = 1;
	else
		node->up = 0;

	if(node->x + 1 > row - 1)
		node->down = 1;
	else if(miGongArr[node->x + 1][node->y] == 1)
		node->down = 1;
	else
		node->down = 0;

	if(node->y - 1 < 0)
		node->left = 1;
	else if(miGongArr[node->x][node->y - 1] == 1)
		node->left = 1;
	else
		node->left = 0;

	if(node->y + 1 > col - 1)
		node->right = 1;
	else if(miGongArr[node->x][node->y + 1] == 1)
		node->right = 1;
	else
		node->right = 0;
	switch (from)
	{
		case WX_LEFT:
			node->left = 1;
			break;
		case WX_RIGHT:
			node->right = 1;
			break;
		case WX_UP:
			node->up = 1;
			break;
		case WX_DOWN:
			node->down = 1;
			break;
		default:
			break;
	}
}
template <class T>
void MiGong<T>::printResult()
{
	string *pStr = new string[row * col + row];
	string *tempStr = pStr;
	int i = 0;
	while(1)
	{
		cout << i << endl;
		if(i % col == 0 && i != 0)
		{
			*tempStr++ = "\n";
			if(i == row * col)
				break;
		}
		*tempStr++ = "* ";
		i++;
	}
	for(int i = resultNum - 1; i >= 0; i--)
	{
		pStr[resutlArr[i * 2] * (col + 1) + resutlArr[i * 2 + 1]] = "+ ";
	}
	i = 0;
	while(i != row * col + row)
	{
		cout<<pStr[i];
		i++;
	}
}
template <class T>
void MiGong<T>::searchDis(MiGongNode *node, MyStack<MiGongNode> &stack, int x, int y, int from, bool &isFind)
{
	if(x == xEnd && y == yEnd)
	{
		node->x = x;
		node->y = y;
		node->left = 1;
		node->right = 1;
		node->up = 1;
		node->down = 1;
		stack.push(*node);
		isFind = true;
		return;
	}
	if(stack.isEmpty() && node->left == 1 &&node->right == 1 && node->up == 1 && node->down == 1)
		return;
	judge(node,from);
	if(node->left == 0 && isFind == false)
	{
		stack.push(*node);
		node->x = x;
		node->y = y - 1;
		searchDis(node, stack, x, y - 1, WX_RIGHT, isFind);
	}
	if(node->right == 0 && isFind == false)
	{
		stack.push(*node);
		node->x = x;
		node->y = y + 1;
		searchDis(node, stack, x, y + 1, WX_LEFT, isFind);
	}
	if(node->up == 0 && isFind == false)
	{
		stack.push(*node);
		node->x = x - 1;
		node->y = y;
		searchDis(node, stack, x - 1, y, WX_DOWN, isFind);
	}
	if(node->down == 0 && isFind == false)
	{
		stack.push(*node);
		node->x = x + 1;
		node->y = y;
		searchDis(node, stack, x + 1, y, WX_UP,isFind);
	}
	if(isFind == false)
		*node = stack.pop();
		return;
}
#endif
