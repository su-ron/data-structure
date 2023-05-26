#include<stdio.h>
#include<stdlib.h>
//不带头结点的单链表

//定义一个单链表
typedef struct LNode{
   int data;   //定义每个节点的数据类型，每个节点存放一个数据元素
   struct LNode *next;//指针指向下一个节点
}LNode,*LinkList;

/*
LNode* 强调这是一个节点
LinkList 强调这是一个单链表
*/

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){//逆向建立单链表
  LNode*s;int x;
  L=(LinkList)malloc(sizeof(LNode));//创建头结点，L为头指针
  L->next=NULL;  //初始为空链表
  scanf("%d",&x);  //输入节点的值
  while(x!=9999){  //输入9999表示结束
  s=(LNode*)malloc(sizeof(LNode));
  s->data=x;
  s->next=L->next;//最后一个节点指向空
  L->next=s;    //将新结点插入表中，L为头指针
  scanf("%d",&x);
  }
}

//初始化一个空链表
bool InitList(LinkList &L){  
    L=NULL;//空表，暂时还没有任何结点
    return true;
}

//判断单链表是否为空
bool Empty(LinkList L){
    if(L==NULL)
    return true;
    else
    return false;
}

//在第i个位置插入元素e（不带头结点）
bool ListInsert(LinkList &L,int i,int e){
   
    if(i<1)
    return false;
     if(i==1)
     {
        LNode*s=(LNode*)malloc(sizeof(LNode));
        s->next=L;
        s->data=e;
        L=s;
        return true;
     }
    LNode* p;//指针指向的是当前扫描到的结点
    int j=0; //当前p指向第几个结点
    while(p!=NULL&&j<i-1){  //循环找到第i-1个节点
     p=p->next;
     j++;
    }
    if(p==NULL)//i值不合法
    return false;
    LNode *s =(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

void test()
{
    LinkList L;//声明一个指向单链表的指针

    //初始化一个空表
    InitList(L);
}

int main()
{
    test();
    return 0;
}