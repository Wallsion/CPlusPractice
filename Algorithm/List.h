#pragma once
struct listnode
{
	int key;
	listnode *nodePre;
	listnode *nodeNext;
};
typedef struct listnode Lnode;
class List
{
public:
	List(void);
	virtual ~List(void);
	bool Linserthead(Lnode *node);
	bool List::LinsertTail(Lnode *node);
	bool Linsert(int key,Lnode *node);
	Lnode * Lsearch(int key);
	bool Ldelete(int key);
	bool Ldestroy();
	int printListkey();
private:
	bool Lerroout(int label = -1);
private:
	Lnode *head;
};

