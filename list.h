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
	 //构造链表
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
	 //寻找链表中某个节点
	 Node *Find(const DataType &d);
	 void Insert(Node* pos,const DataType &d);
	 void Reverse();
	 void sort();
	 //合并两个有序单链表。。有一点问题
	 Node* Merge(Slist slist1,Slist slist2);
	 void Remove(const DataType &d);
	 void RemoveAll(const DataType &d);
	 //删除链表中倒数第k个节点
	 void Delk(int k);
	 //在指定节点后边插入一个节点
	 void InsertFrontNode(Node* pos,const DataType &d);
	 //寻找链表的中间节点
	 Node* FindMidNode();
	//求链表的长度
	 int GetlistLength();
	 //销毁链表
	 void Destory();
	//判断链表是否带环
	 Node* Checkcycle();
	 //获取环的入口节点
	 Node* GetcycleEntryNode(Node* meetnode);
	 
	 
 private:
	 Node *_head;
	 Node *_tail;
 };
