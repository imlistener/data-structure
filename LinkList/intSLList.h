#pragma once
#ifndef INT_LINKED_LIST
#define INE_LINKED_LIST

/*
类名：单向链表的节点
功能：组成链表的节点，
成员：int info; 是节点的内容存放，IntSLLNode *next;保存当前节点的下一个节点的地址
*/
class IntSLLNode {
public:
	IntSLLNode() {

	}
	IntSLLNode(int el,IntSLLNode * ptr=0) {
		this->info = el;
		this->next = ptr;
	}
public:
	int info;
	IntSLLNode *next;
};

class intSLList
{
public:
	intSLList();
	~intSLList();
	int isEmpty() {
		return  head == 0;
	}

	void addtoHead(int el);
	void addtoTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int)const;
private:
	IntSLLNode *head;
	IntSLLNode *tail;
};

#endif

