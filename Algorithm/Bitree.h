#pragma once
#include "All.h"
class Bitree
{
public:
	bool BiTreeCreate(void *dataaddr,int datanum,int type);
	bool BiTreeDestory();
	bool BiTreePreOrder(tNode *tnode);
	bool BiTreeInOrder(tNode*tnode);
	bool BiTreePostOrder(tNode*tnode);
	bool BiTreeLevelOrder(tNode*tnode);
	int BiTreeHigh(tNode*tnode);
	int BiTreeLeafnumber(tNode*tnode);
	bool BiTreeExchange(int index);
	tNode* GetRoot();
	Bitree(void);
	~Bitree(void);
private:
	tNode *TreeRoot;
private:
	int treecreatepre(tNode *Treenode,int *dataaddr,int index,int datanum);
	bool treecreatein(tNode *Treenode,int *dataaddr,int datanum);
	bool treecreatepos(tNode *Treenode,int *dataaddr,int datanum);
	bool treecreatelist(tNode *Treenode,std::string *str);
};
