#include<iostream>
#include<malloc.h>
using namespace std;

#define ElemType int
#define ERROR 1
#define OK 0

typedef struct CLNode
{
	ElemType data;//������
	struct CLNode *next; 
}CLNode,*CLinkList;

//��ʼ������
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

//˳�򴴽�����
int Create_CL(CLinkList &L)
{
	int n;
	CLNode *p,*q;
	cout<<"����������ݸ�����";
	cin>>n;
	L=(CLinkList)malloc(sizeof(CLNode));
	L->next=L;
	q=L;
	cout<<"�밴��С�����˳���������ݣ�";
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

//ɾ������L�ĵ�i��Ԫ��
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

//������L�ĵ�i��λ�ò���Ԫ��
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

//�������La��Lb�ϲ�ΪLc
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

//�������L�ĸ���Ԫ��
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
	cout<<"�����La={";
	Print(La);
	cout<<"}"<<endl;
	Delete_CL(Lb,3);
	cout<<"ɾ����Lb={";
    Print(Lb);
	cout<<"}"<<endl;
	cout<<"��La��Lb�ϲ���Lc={";
	Merge_CL(La,Lb,Lc);
	Print(Lc);
	cout<<"}"<<endl;
}