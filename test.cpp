#include"list.h"

void test1()
	 {
	 Slist slist1;
	slist1.pushback(1);
	slist1.pushback(2);
	slist1.pushback(3);
	slist1.pushback(4);
	slist1.Destory();
	cout<<slist1<<endl;
	 }
    void test2()
	{
	Slist slist1;
	slist1.pushfront(1);
	slist1.pushfront(2);
	slist1.pushfront(4);
	slist1.pushfront(4);
	slist1.RemoveAll(4);
	cout<<slist1<<endl;
	}
	void test3()
	{
	Slist slist1;
	slist1.pushfront(3);
	slist1.pushfront(2);
	slist1.pushfront(1);
	slist1.Reverse();
	cout<<slist1<<endl;
	}
	void test4()
	{
	 Slist slist1;
	slist1.pushfront(1);
	slist1.pushfront(3);
	slist1.pushfront(5);
	slist1.pushfront(7);
	slist1.Delk(2);
	cout<<slist1;
	}
	void test5()
	{
	 Slist slist1;
	slist1.pushfront(1);
	slist1.pushfront(3);
	slist1.pushfront(4);
	slist1.pushfront(5);
	Node* cur=slist1.Find(1);
	slist1.InsertFrontNode(cur,2);
	cout<<slist1;
	}

	void test6()
	{
	 Slist slist1;
	slist1.pushfront(1);
	slist1.pushfront(2);
	slist1.pushfront(3);
	slist1.pushfront(4);
	slist1.sort();
	cout<<slist1;
	}
	void test8()
	{
	 Slist slist1;
	slist1.pushfront(1);
	slist1.pushfront(2);
	slist1.pushfront(3);
	slist1.pushfront(4);
	slist1.pushfront(5);
	int count=slist1.GetlistLength();
	cout<<count;
	}
	void test9()
	{
	int i=0;
	Slist slist1;
	for(i=1;i<8;i++)
	{
		slist1.pushfront(i);
	}
	Node* end=slist1.Find(8);
	Node* cur=slist1.Find(2);
	end->_next=cur;
	cur=slist1.Checkcycle();
	if(cur!=NULL)
		cout<<cur;
	}
int main()
{
	test9();
	system("pause");
	return 0;

}