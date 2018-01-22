#pragma once
#include <string>
#include <iostream>
typedef struct  treenode
{
	int data;
	treenode *lfetchild;
	treenode *rightchild;
}tNode;
struct listnode
{
	int key;
	listnode *nodePre;
	listnode *nodeNext;
};
typedef struct listnode Lnode;
