#include "stdafx.h"
#include "List.h"
#include <iostream>
List::List(void)
{
	head = new Lnode;
	head->key = 0XFFFFFFFF;
	head->nodeNext = head;
	head->nodePre = head;
}


List::~List(void)
{
}

bool List::Linserthead(Lnode *node)
{
	node->nodeNext = head->nodeNext;
	head->nodeNext->nodePre = node;
	head->nodeNext = node;
	node->nodePre = head;
	return true;
}
bool List::LinsertTail(Lnode *node)
{
	node->nodePre = head->nodePre;
	head->nodePre->nodeNext = node;
	head->nodePre = node;
	node->nodeNext = head;
	return true;
}
bool List::Linsert(int key,Lnode *node)
{
	 if(head->nodeNext == head)
	{
		head->nodeNext = node;
		head->nodePre = node;
		node->nodePre = head;
		node->nodeNext = head;
		Lerroout(0);
		return true;
	}
	else
	{
		Lnode *temnode = head->nodeNext;
		while(temnode != head)
		{
			if(temnode->key == key)
			{
				node->nodeNext = temnode->nodeNext;
				temnode->nodeNext->nodePre = temnode;
				temnode->nodeNext = node;
				node->nodePre = temnode;
				return true;
			}
			else
			{
				temnode = temnode->nodeNext;
			}
		}
			node->nodeNext = temnode->nodeNext;
			temnode->nodeNext->nodePre = temnode;
			temnode->nodeNext = node;
			node->nodePre = temnode;
			Lerroout(1);
			return true;
	}
}
Lnode * List::Lsearch(int key)
{
	Lnode *temnode = head->nodeNext;
	while(temnode != head)
	{
		if(temnode->key == key)
		{
			return temnode;
		}
		temnode = temnode->nodeNext;
	}
	Lerroout();
	return nullptr;
}
bool List::Ldelete(int key)
{
	if(head->nodeNext == head)
	{
		Lerroout(2);
		return false;
	}
	else
	{
		Lnode *temnode = head->nodeNext;
		while (temnode != head)
		{
			if(temnode->key == key)
			{
				temnode->nodeNext->nodePre = temnode->nodePre;
				temnode->nodePre->nodeNext = temnode->nodeNext;
				//delete temnode;
				return true;
			}
			temnode = temnode->nodeNext;
		}
		Lerroout(3);
		return false;
	}
}
bool List::Ldestroy()
{
	Lnode *temnode = head->nodeNext;
	Lnode *temdeletenode;
	while (temnode != head)
	{
		temdeletenode = temnode;
		temnode = temnode->nodeNext;
		delete temdeletenode;
	}
	delete head;
	return true;
}
int List::printListkey()
{
	Lnode *temnode = head->nodeNext;
	while (temnode != head)
	{
		std::cout<<temnode->key<<" ";
		temnode = temnode->nodeNext;
	}
	return 1;
}
bool List::Lerroout(int label)
{
	switch (label)
	{
	case 0:
		std::cout <<"当前链表为空！"<<std::endl;
		return 1;
	case 1:
		std::cout <<"为找匹配值值，插入到末尾！"<<std::endl;
		return 1;
	case 2:
		std::cout <<"当前链表为空无法删除！"<<std::endl;
		return 1;
	case 3:
		std::cout <<"未找到匹配节点无法删除！"<<std::endl;
		return 1;
	default:
		std::cout <<"没找到！"<<std::endl;
		break;
	}
	return true;
}