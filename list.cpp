
#include"list.h"
#include<assert.h>
//1<<输出运算符的重载
ostream& operator<<(ostream &os,Slist &s)
 {
	 if(s._head==NULL)
	 {
		return os;
	 }
	Node *cur=s._head;
	 while(cur!=NULL)
	 {
		 os<<cur->_data<<"->";
		 cur=cur->_next;
	 }
		os<<"over"<<endl;
		return os;
 }
//2头插法建立单链表
 void Slist::pushback(const DataType &d)
 {
 Node * newNode=new Node(d);
	 if(_head==NULL)
	 {
	 _head=newNode;
	 _tail=_head;
	 }
	 else
	 {
	 _tail->_next=newNode;
	 _tail=newNode;
	 }
 }
 //3尾删除法单链表
	 void  Slist::popback()
	{
		Node *cur=_head;
		//没有节点
		if(_head=NULL)
		{
			return;
		}
		//有一个节点
		if(_head==_tail)
		{
		delete _head;
		_head=NULL;
		_tail=NULL;
		return;
		}
		//有好多个节点
		while(cur->_next!=_tail)
		{
		cur=cur->_next;
		}
		delete _tail;
		_tail=cur;
		_tail->_next=NULL;
	}
//3头插法建立单链表
	 void  Slist::pushfront(const DataType &d)
	 {
     Node* newNode=new Node(d);
	 if(_head==NULL)
		 {
		 _head=newNode;
		 _tail=_head;
		 }
	 else
		 {
		 newNode->_next=_head;
		 _head=newNode;
		 }
	 }
//4头删
	 void  Slist::popfront()
	 {
		 //如果链表为空则直接返回
		 if(_head==NULL)
		 {
		   return;
		 }
		 //否则挨个删除
		 Node *del=_head;
		 _head=_head->_next;
		 delete del;
	 }
//5在单链表中查找某个数据的节点
	 Node*  Slist::Find(const DataType &d)
	 {
		 Node *cur=_head;
		 if(_head==NULL||_head->_next==NULL)
		 {
		 return _head;
		 }
		 while(cur)
		 {
			 if(cur->_data==d)
			 {
			    return cur;
			 }
		    cur=cur->_next;
		 }
	     return NULL;
	 }
	// 6在当前节点后边插入某个数据
	 void  Slist::Insert(Node* pos,const DataType &d)
	 {
	 Node* newNode=new Node(d);
	 if(pos==_tail)
	 {
	 _tail->_next=newNode;
	 _tail=newNode;
	 }
	 else
	 {
	 newNode->_next=pos->_next;
	  pos->_next=newNode;
	 }	
	 }
	 //7翻转单链表
	 void Slist::Reverse()
	 {
		 Node *th=NULL;
		 Node *q =NULL;
		 Node *p=_head;
		 if(_head==NULL||_head->_next==NULL)
		 {
		    return;
		 }
		while(p)
		{
		    q=p;
			p=p->_next;
			q->_next=th;
			th=q;
		}
		_head=th;
	 }
//8对单链表进行排序
 void Slist:: sort()
	 {
		 Node* end=NULL;
		 Node* cur=_head;
     if(cur==NULL||cur->_next==NULL)
		 {
		    return;
		 }	
	 while(cur->_next!=end)
	 {
		 while(cur!=NULL&&cur->_next!=end)
		 {
	       if(cur->_data>cur->_next->_data)
		   {
			   DataType tmp=cur->_data;
			   cur->_data=cur->_next->_data;
			   cur->_next->_data=tmp;
		   }
	       cur=cur->_next;
		 }
	     end=cur;
		 cur=_head;
	 }
	 }
//9合并两个有序单链表
	 Node* Merge(Node* _head1,Node* _head2)
	 {
	   Node *newHead=NULL;
	  if(_head1==_head2)
	  {
	  return _head1;
	  }
	  if(_head1==NULL&&_head2!=NULL)
	  {
	    return _head2;
	  }
	 if(_head1!=NULL&&_head2==NULL)
	 {
	    return _head1;
	 }
	 if(_head1->_data<_head2->_data)
	 {
	  newHead=_head1;
	 _head1=_head1->_next;
	 }
	 else
	 {
	 newHead=_head2;
	 _head2=_head2->_next;
	 }
	 Node* cur=newHead;
	 while(_head1&&_head2)
	 {
	 if(_head1->_data<_head2->_data)
	 {
	   cur->_next=_head1;
	  _head1=_head1->_next;
	 }
	 else
	 {
	 cur->_next=_head2;
	 _head2=_head2->_next;
	 }
	 cur=cur->_next;
	 }
	 if(_head1)
	 {
	 cur->_next=_head1;
	 }
	 else
	 {
	 cur->_next=_head2;
	 }
	 return newHead;
	 }

	//10删除链表中的某个值为d的节点
	 void  Slist::Remove(const DataType &d)
	 {
		 Node *cur=_head;
		 Node * del=NULL;
		 Node *prve=NULL;
		 if(cur==NULL)
		 {//若链表为空则直接返回
		  return;
		 }
		 //若cur不为空 则一直往下走
		 while(cur)
		 {
		 
			 if(cur->_data==d)
			 {
				del=cur;
				//若要找的为第一个节点
				 if(cur=_head)
				 {
				 _head=_head->_next;
				 }
				 else
				 {
				 prve->_next=cur->_next;
				 delete del;
				 break;
				 }
			 }
			 prve=cur;
			 cur=cur->_next;
		 }
	 }
	 //11删除链表中的所有值为d的节点
	 void  Slist::RemoveAll(const DataType &d)
	 {
	  Node *cur=_head;
		 Node * del=NULL;
		 Node *prve=NULL;
		 if(cur==NULL)
		 {//若链表为空则直接返回
		  return;
		 }
		 //若cur不为空 则一直往下走
		 while(cur)
		 {
		
			 if(cur->_data==d)
			 {
				del=cur;
				 //若要找的为第一个节点
				 if(cur=_head)
				 {
				 _head=_head->_next;
				 cur=_head;
				 }
				 else
				 {
				 prve->_next=cur->_next;
				 cur=prve->_next;
				 delete del;
				
				 }
			 }
			 else
			 {
			 prve=cur;
			 cur=cur->_next;
			 }
		 }
	 }

//12删除链表中倒数第k个节点
	 void Slist::Delk(int k)
	 {
		 assert(k>1);
		 Node* p1=_head;
		 Node* p2=_head;
		 while(--k)
	 {
		p1=_head->_next;
	 }
	 while(p1->_next)
	 {
		 p1=p1->_next;
		 p2=p2->_next;
	 }
		 Node* del=p2->_next;
		 p2->_data=p2->_next->_data;
		 p2->_next=p2->_next->_next;
		 delete del;
	 }
//13在当前链表前插入一个数据
	 void Slist::InsertFrontNode(Node* pos,const DataType &d)
	 {
	 Node * newNode=new Node(d);
	 newNode->_next=pos->_next;
	 pos->_next=newNode;
	 DataType tmp=pos->_data;
	 pos->_data=pos->_next->_data;
	 pos->_next->_data=tmp;
	 }

	 //14寻找链表的中间节点
	 Node* Slist:: FindMidNode()
	 {
	   Node *fast=_head;
	   Node *slow=_head;
	   if(fast==NULL)
	   {
	      return NULL;
	   }
	   if(fast!=NULL&&fast->_next!=NULL)
	   {
		   fast=fast->_next->_next;
		   slow=slow->_next;
	   }
	     return slow;
	 }
	//15求链表的长度
	int  Slist:: GetlistLength()
	 {
		 int count=0;
		 Node *cur=_head;
		 while(cur)
		 {
		 count++;
		 cur=cur->_next;
		 }
	    return count;
	 }
	void Slist::Destory()
	{
	  Node* cur=_head;
	  Node* del=NULL;
	  if(_head=NULL)
	  {
	    return;
	  }
	  else
	  {
		  while(cur)
		  {
			 del=cur;
			cur=cur->_next;
			 delete del;
			 del=NULL;
		  }
	  }
	}
	Node* Slist::Checkcycle()
	{
	   Node* fast=_head;
	   Node*slow=_head;
	   while(fast&&fast->_next)
	   {
		   fast=fast->_next->_next;
		   slow=slow->_next;
		 if(fast==slow)
		   {
			 return slow;
		   }
	   }
	   return NULL;
	}

	Node* Slist::GetcycleEntryNode(Node* meetnode)
	{
	  Node* entry=_head;
	  Node* meet=meetnode;
	  while(entry!=meet)
	  {
	  entry=entry->_next;
	  meet=meet->_next;
	  
	  }
	  return entry;
	}
	