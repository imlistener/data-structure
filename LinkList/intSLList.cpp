#include "intSLList.h"

intSLList::intSLList()
{
	head = tail = 0;
}

intSLList::~intSLList()
{
}

/*
��Ա������addtoHead
�β�˵����int el;����ָ��������
�������������ݴ�������ݴ����ڵ㣬���ҽ������Ľڵ������������ײ�
*/
void intSLList::addtoHead(int el) {
	IntSLLNode *temp = new IntSLLNode(el);
	if (!isEmpty()) {
		temp->next = head;
		head = temp;
	}
	else head = tail = temp;

	//����
	head = new IntSLLNode(el, head);
	if (tail == 0) {
		tail = head;
	}
}

/*
��Ա������addtoTail
�β�˵����int el;����ָ��������
�������������ݴ�������ݴ����ڵ㣬���ҽ������Ľڵ�����������β��
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
��Ա������deleteFromHead
�β�˵������
����ֵ  ��int ,���ر�ɾ���ڵ��ֵ
������������������ײ�ɾ���ڵ㣬���ҷ��ر�ɾ���ڵ������
*/
int intSLList::deleteFromHead() {
	int el;
	IntSLLNode *temp = head;

	//������
	
	if (head == tail) {			//һ���ڵ������
		head = tail = 0;
		
	}else					    //����ڵ������
	{
		head = head->next;
	}
	el = temp->info;
	delete temp;

	return el;
}

/*
��Ա������deleteFromTail
�β�˵������
����ֵ  ��int ,���ر�ɾ���ڵ��ֵ
�����������������β��ɾ���ڵ㣬���ҷ��ر�ɾ���ڵ������
*/
int intSLList::deleteFromTail() {

	int el;
	IntSLLNode *temp1 = head;
	IntSLLNode *temp2 = tail;
	//������

	if (head == tail) {			//һ���ڵ������
		head = tail = 0;
	}
	else					    //����ڵ������
	{
		for (; temp1->next != tail; temp1 = temp1->next);
		tail = temp1;
	}
	el = temp2->info;
	delete temp2;

	return el;
}

/*
��Ա������deleteNode
�β�˵����int el;����ָ��������
�������������ݴ��������ɾ���ڵ㣬��ɾ���Ľڵ��info�봫����β�һ��
*/
void intSLList::deleteNode(int el) {
	if (head!=0)					     //�ǿ�����
	{
		if (head==tail&&el==head->info)                    //ֻ��һ���ڵ㣬���Ҿ���Ҫɾ���Ľڵ�
		{
			delete head;
			head = tail = 0;
		}	
		else if (el=head->info)							  //����ڵ������£���ɾ���Ľڵ����ײ�
		{
			IntSLLNode *temp = head;
			head = head->next;
			delete temp;
			
		}
		else											  //����ڵ������£��ڵ��������м�(�����ײ�)
		{
			IntSLLNode *pre = head;
			IntSLLNode *next = head->next;

			for (; next != 0 &&!(el == next->info); pre = pre->next, next = next->next);
			if (next != 0) {
				pre->next = next->next;
				//���ҵ��Ľڵ��Ƿ���β��,��β��ʱ��tailǰ��
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
��Ա������isInList
�β�˵����int el;����ָ��������
�������������ݴ���������ж��������Ƿ����ָ�����ݵĽڵ�*/
bool  intSLList::isInList(int el)const {
	IntSLLNode *temp = head;
	for (; temp != 0 && !(el == temp->info););
	return temp != 0;
}