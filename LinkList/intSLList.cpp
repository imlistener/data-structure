#include "intSLList.h"

intSLList::intSLList()
{
	head = tail = 0;
}

intSLList::~intSLList()
{
}

/*
成员函数：addtoHead
形参说明：int el;传入指定的内容
功能描述：根据传入的内容创建节点，并且将创建的节点插入在链表的首部
*/
void intSLList::addtoHead(int el) {
	IntSLLNode *temp = new IntSLLNode(el);
	if (!isEmpty()) {
		temp->next = head;
		head = temp;
	}
	else head = tail = temp;

	//更简单
	head = new IntSLLNode(el, head);
	if (tail == 0) {
		tail = head;
	}
}

/*
成员函数：addtoTail
形参说明：int el;传入指定的内容
功能描述：根据传入的内容创建节点，并且将创建的节点插入在链表的尾部
*/
void intSLList::addtoTail(int el) {
	IntSLLNode * temp = new IntSLLNode(el);
	if (!isEmpty()) {
		tail->next = temp;
		tail = temp;
	}
	else head = tail = temp;
}

/*
成员函数：deleteFromHead
形参说明：无
返回值  ：int ,返回被删除节点的值
功能描述：从链表的首部删除节点，并且返回被删除节点的内容
*/
int intSLList::deleteFromHead() {
	int el;
	IntSLLNode *temp = head;

	//空链表
	
	if (head == tail) {			//一个节点的链表
		head = tail = 0;
		
	}else					    //多个节点的链表
	{
		head = head->next;
	}
	el = temp->info;
	delete temp;

	return el;
}

/*
成员函数：deleteFromTail
形参说明：无
返回值  ：int ,返回被删除节点的值
功能描述：从链表的尾部删除节点，并且返回被删除节点的内容
*/
int intSLList::deleteFromTail() {

	int el;
	IntSLLNode *temp1 = head;
	IntSLLNode *temp2 = tail;
	//空链表

	if (head == tail) {			//一个节点的链表
		head = tail = 0;
	}
	else					    //多个节点的链表
	{
		for (; temp1->next != tail; temp1 = temp1->next);
		tail = temp1;
	}
	el = temp2->info;
	delete temp2;

	return el;
}

/*
成员函数：deleteNode
形参说明：int el;传入指定的内容
功能描述：根据传入的内容删除节点，被删除的节点的info与传入的形参一致
*/
void intSLList::deleteNode(int el) {
	if (head!=0)					     //非空链表
	{
		if (head==tail&&el==head->info)                    //只有一个节点，而且就是要删除的节点
		{
			delete head;
			head = tail = 0;
		}	
		else if (el=head->info)							  //多个节点的情况下，被删除的节点在首部
		{
			IntSLLNode *temp = head;
			head = head->next;
			delete temp;
			
		}
		else											  //多个节点的情况下，节点中链表中间(不在首部)
		{
			IntSLLNode *pre = head;
			IntSLLNode *next = head->next;

			for (; next != 0 &&!(el == next->info); pre = pre->next, next = next->next);
			if (next != 0) {
				pre->next = next->next;
				//被找到的节点是否在尾部,在尾部时，tail前移
				if (next == tail) {
					tail = pre;
				}
				delete next;
			}
		}
	}
	return;
}

/*
成员函数：isInList
形参说明：int el;传入指定的内容
功能描述：根据传入的内容判断链表中是否存在指定内容的节点*/
bool  intSLList::isInList(int el)const {
	IntSLLNode *temp = head;
	for (; temp != 0 && !(el == temp->info););
	return temp != 0;
}