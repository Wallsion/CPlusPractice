#pragma once
struct  treenode
{
	int key;
	treenode *pParenet;
	treenode *pleftchild;
	treenode *prightchild;
};
class binarytree
{
public:
	binarytree();
	~binarytree();
	bool Bcreatetree();
};

