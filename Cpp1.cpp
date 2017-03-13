#include<iostream>
#include<malloc.h>
using namespace std;

#define ElemType int
#define ERROR 1
#define OK 0

typedef struct CLNode
{
	ElemType data;//数据域
	struct CLNode *next; 
}CLNode,*CLinkList;

//初始化链表
int Initial_CL(CLinkList &L)
{
	L=(CLinkList)malloc(sizeof(CLNode));
	if(L)
	{
		L->next=L;
		return OK;
	}
	return ERROR;
}

//顺序创建链表
int Create_CL(CLinkList &L)
{
	int n;
	CLNode *p,*q;
	cout<<"请输入的数据个数：";
	cin>>n;
	L=(CLinkList)malloc(sizeof(CLNode));
	L->next=L;
	q=L;
	cout<<"请按从小到大的顺序输入数据：";
	for(int i=n;i>0;--i)
	{
		p=(CLinkList)malloc(sizeof(CLNode));
		cin>>p->data;
		p->next=q->next;
		q->next=p;
		q=p;
		q->next=L;
	}
	
	return OK; 
}

//删除链表L的第i个元素
int Delete_CL(CLinkList &L,int i)
{
	CLNode *p,*q;
	int j=0;
	p=L;
	while(p->next!=L&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(p->next==L || j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	return OK;

}

//在链表L的第i个位置插入元素
int Insert_CL(CLinkList &L,int i,ElemType e)
{
	CLNode *p,*q;
	int j=0;
	p=L->next;
	while(p!=L && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(p==L|| j>i-1) return ERROR;
	q=(CLinkList)malloc(sizeof(CLNode));
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK;
}

//将升序的La，Lb合并为Lc
int Merge_CL(CLinkList &La,CLinkList &Lb,CLinkList &Lc)
{
	CLNode *pa,*pb,*pc;
	pa=La->next;
	pb=Lb->next;
	pc=La;
	Lc=pc;
	while(pa!=La && pb!=Lb)
	{
		if(pa->data<pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->data=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			pb=pb->next;
		}
		else if(pa->data>pb->data) 
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	if(pa==La) 
	{
		while(pb!=Lb)
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		pc->next=Lc;
	}
	if(pb==Lb) 
	{
		while(pa!=La)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		pc->next=Lc;
	}
	
	return OK;
}

//输出链表L的各个元素
void Print(CLinkList &L)
{
	CLNode *p;
	p=L->next;
	while(p!=L)
	{
		
		cout<<p->data;
		p=p->next;
		cout<<",";
	}
}

void main()
{
	CLinkList La,Lb,Lc;
	Create_CL(La);
	cout<<"La={";
	Print(La);
	cout<<"}"<<endl;
	Create_CL(Lb);
	cout<<"Lb={";
	Print(Lb);
	cout<<"}"<<endl;
	Initial_CL(Lc);
	Insert_CL(La,3,4);
	cout<<"插入后La={";
	Print(La);
	cout<<"}"<<endl;
	Delete_CL(Lb,3);
	cout<<"删除后Lb={";
    Print(Lb);
	cout<<"}"<<endl;
	cout<<"表La和Lb合并后Lc={";
	Merge_CL(La,Lb,Lc);
	Print(Lc);
	cout<<"}"<<endl;
}