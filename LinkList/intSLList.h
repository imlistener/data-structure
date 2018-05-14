#pragma once
#ifndef INT_LINKED_LIST
#define INE_LINKED_LIST

/*
��������������Ľڵ�
���ܣ��������Ľڵ㣬
��Ա��int info; �ǽڵ�����ݴ�ţ�IntSLLNode *next;���浱ǰ�ڵ����һ���ڵ�ĵ�ַ
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

