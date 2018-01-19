#include "stdafx.h"
#include <iostream>
#include <string>
#include "Quenue.h"
int quenue::erroout(int ll = -1)
{
	switch(ll)
	{
		case 0:
			std::cout << "队列满了！";
			return 1;
		case 1:
			std::cout << "队列空了";
			return 1;
		case 2:
			return 1;
		default:
			std::cout << "队列创建错误";
	return 1;
	}
}
quenue::quenue()
{
}

quenue::~quenue()
{
	delete[] qzone;
}
bool quenue::Qcreate(int q_length)
{
	qzone = new int[q_length+1];
	qhead = qzone;
	qtail = qzone;
	qcurlength = 0;
	cyclelabl = &qzone[q_length];
	qlength = q_length;
	return true;
}
bool quenue::Qdestory()
{
	delete[] qzone;
	return 1;
}
bool quenue::Qin(int num)
{
	if (qcurlength == qlength)
	{
		erroout(0);
		return false;
	}
	else
	{
		if(qtail != cyclelabl)
		{
		 *qtail = num;
		  qtail++;
		}
		else
		{
		 *qtail = num;
		  qtail = qzone;
		}
		qcurlength ++;
		return true;
	}

}
bool quenue::Qin(float num)
{
	return 1;
}
int quenue::Q_intout()
{
	if (qcurlength == 0)
	{
		erroout(1);
		return false;
	}
	else
	{
		int tem;
		if(qhead != cyclelabl)
		{
			tem = *qhead;
			qhead++;
		}
		else
		{
			tem = *qhead;
			qhead = qzone;
		}
		return tem;
	}
}
float quenue::Q_floatout()
{
	return 1;
}