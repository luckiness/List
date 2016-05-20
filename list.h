#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
 struct Node
{
	DataType _data;
	struct Node * _next;
	Node(const DataType &d)
		:_data(d)
		,_next(NULL)
	{
	
	}

};

 class Slist
 {
	 friend ostream & operator<<(ostream &os,Slist &s);
 public:
	 //��������
	 Slist()
		 :_head(NULL)
		 ,_tail(NULL)
	 {
	 
	 }
	 ~Slist()
	 {
	 if(_head==NULL)
	 {
	 return ;
	 }
	 Node *cur=_head;
	 while(cur!=NULL)
	 {
	 Node *del=cur;
	 cur=cur->_next;
	 delete del;
	 }
	 delete cur;
	 _head=NULL;
	 _tail=NULL;
	 }
	 Slist(const Slist &s)
		 :_head(NULL)
		 ,_tail(NULL)
	 {
		 Node *cur=_head;
		 while(cur)
		 {
		 pushback(cur->_data);
		 cur=cur->_next;
		 }
	 
	 }
 public:
	 void pushback(const DataType &d);
	 void popback();
	 void pushfront(const DataType &d);
	 void popfront();
	 //Ѱ��������ĳ���ڵ�
	 Node *Find(const DataType &d);
	 void Insert(Node* pos,const DataType &d);
	 void Reverse();
	 void sort();
	 //�ϲ�����������������һ������
	 Node* Merge(Slist slist1,Slist slist2);
	 void Remove(const DataType &d);
	 void RemoveAll(const DataType &d);
	 //ɾ�������е�����k���ڵ�
	 void Delk(int k);
	 //��ָ���ڵ��߲���һ���ڵ�
	 void InsertFrontNode(Node* pos,const DataType &d);
	 //Ѱ��������м�ڵ�
	 Node* FindMidNode();
	//������ĳ���
	 int GetlistLength();
	 //��������
	 void Destory();
	//�ж������Ƿ����
	 Node* Checkcycle();
	 //��ȡ������ڽڵ�
	 Node* GetcycleEntryNode(Node* meetnode);
 private:
	 Node *_head;
	 Node *_tail;
 };