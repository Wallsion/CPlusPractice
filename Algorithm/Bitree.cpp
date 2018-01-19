#include "Bitree.h"
#include <queue>
Bitree::Bitree(void)
{
}

Bitree::~Bitree(void)
{
}
bool Bitree::BiTreeCreate(void *dataaddr,int datanum,int type)
{
	TreeRoot = new tNode;
	switch (type)
	{
	case -1://前序
		treecreatepre(TreeRoot,(int*)dataaddr,0,datanum);
		break;
	case 0 ://中序
		treecreatein(TreeRoot,(int*)dataaddr,datanum);
		break;
	case 1://后序
		treecreatepos(TreeRoot,(int*)dataaddr,datanum);
		break;
	case 2://广义表
		treecreatelist(TreeRoot,(std::string*)dataaddr);
		break;
	default:
		break;
	}
	return 1;
}
int Bitree::treecreatepre(tNode *Treenode,int *dataaddr,int index,int datanum)
{
	if(index > datanum)
		return index;
	if(Treenode == nullptr)
	{
		return ++index;
	}
	else
	{
		Treenode->data = *(dataaddr+index);
		index++;
		if(*(dataaddr+index) == 0x7fffffff)
			Treenode->lfetchild = nullptr;
		else
		Treenode->lfetchild = new tNode;
		index = treecreatepre(Treenode->lfetchild,dataaddr,index,datanum);
		if(*(dataaddr+index) == 0x7fffffff)
			Treenode->rightchild = nullptr;
		else
		Treenode->rightchild = new tNode;
		index = treecreatepre(Treenode->rightchild,dataaddr,index,datanum);
	}
	return index;
}
bool Bitree::treecreatein(tNode *Treenode,int *dataaddr,int datanum)
{
	return 1;
}
bool Bitree::treecreatepos(tNode *Treenode,int *dataaddr,int datanum)
{
	return 1;
}
bool Bitree::treecreatelist(tNode *Treenode,std::string *str)
{
	return 1;
}
bool Bitree::BiTreeDestory()
{
	return 1;
}
bool Bitree::BiTreePreOrder(tNode*tnode)
{
	if (tnode == nullptr)
		return 0;
	std::cout<<tnode->data<<" ";
	BiTreePreOrder(tnode ->lfetchild);
	BiTreePreOrder(tnode ->rightchild);
	return 0;
}
bool Bitree::BiTreeInOrder(tNode*tnode)
{
	if (tnode == nullptr)
		return 0;
	BiTreeInOrder(tnode ->lfetchild);
	std::cout<<tnode->data<<" ";
	BiTreeInOrder(tnode ->rightchild);
	return 0;
}
bool Bitree:: BiTreePostOrder(tNode*tnode)
{
	if (tnode == nullptr)
		return 0;
	BiTreePostOrder(tnode ->lfetchild);
	BiTreePostOrder(tnode ->rightchild);
	std::cout<<tnode->data<<" ";
	return 0;
}
bool Bitree::BiTreeLevelOrder(tNode*tnode)
{
	//using namespace std;
	std::queue<tNode*> Q;
	Q.push(tnode);
	while(!Q.empty())
	{
		tnode = Q.front();
		if(tnode->lfetchild != nullptr)
		Q.push(tnode->lfetchild);
		if(tnode->rightchild != nullptr)
		Q.push(tnode->rightchild);
		std::cout<<Q.front()->data<<" ";
		Q.pop();
		
	}
	return 1;
}
int Bitree::BiTreeHigh(tNode*tnode)
{
	int high = 0;
	if(tnode != nullptr)
	{
		int l1 = BiTreeHigh(tnode->lfetchild);
		int l2 = BiTreeHigh(tnode->rightchild);
		return high = 1 + (l1 > l2 ? l1 : l2);
	}
	return high;
}
int Bitree::BiTreeLeafnumber(tNode*tnode)
{
	int lnodenum = 0;
	int rnodenum = 0;
	if(tnode != nullptr)
	{
		if(tnode ->lfetchild == nullptr && tnode ->rightchild == nullptr)
			return 1;
		else
		{
			lnodenum = BiTreeLeafnumber(tnode ->lfetchild);
			rnodenum = BiTreeLeafnumber(tnode ->rightchild);
			return lnodenum + rnodenum;
		}
	}
	return 0;
}
bool Bitree::BiTreeExchange(int index)
{

	return 1;
} 
tNode* Bitree::GetRoot()
{
	return TreeRoot;
}