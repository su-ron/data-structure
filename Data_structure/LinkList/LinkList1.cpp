#include<stdio.h>
#include<stdlib.h>
//带头结点的单链表

//定义一个单链表
typedef struct LNode{
   int data;   //定义每个节点的数据类型，每个节点存放一个数据元素
   struct LNode *next;//指针指向下一个节点
}LNode,*LinkList;

/*
LNode* 强调这是一个节点
LinkList 强调这是一个单链表
*/
//初始化一个空链表(带头结点)
bool InitList(LinkList &L){  
    L=(LNode*)malloc(sizeof(LNode)); //分配一个头结点
    if(L==NULL)  //内存不足，分配失败
    return false;
    L->next =NULL;//头结点后暂时还没有节点
    return true;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){//逆向建立单链表
  LNode*s;int x;
  L=(LinkList)malloc(sizeof(LNode));//创建头结点，L为头指针
  L->next=NULL;  //初始为空链表
  printf("请输入节点的值(输入9999表示结束):");
  scanf("%d",&x);  //输入节点的值
  while(x!=9999){  //输入9999表示结束
  s=(LNode*)malloc(sizeof(LNode));
  s->data=x;
  s->next=L->next;//最后一个节点指向空
  L->next=s;    //将新结点插入表中，L为头指针
  printf("请输入节点的值(输入9999表示结束):");
  scanf("%d",&x);
  }
}


//判断单链表是否为空
bool Empty(LinkList L){
    if(L==NULL)
    return true;
    else
    return false;
}


//按位查找,返回第i个元素
LNode *GetElem(LinkList L,int i)
{
    if(i<0)
    return NULL;
    LNode*p=L;
    int j=0;
    while(p!=NULL&&j<i)//直到p指向第i个结点，跳出循环
    {
        p=p->next;
        j++;
    }
    return p;  //对于i<0,以及i大于数组长度时，返回值p=NULL;
}

//按值查找
LNode*LocateElem(LinkList L,int e)
{
    LNode*p=L->next;
    //从第一个结点开始查找数据域为e的结点
    while(p!=NULL&&p->data!=e)
    p=p->next;
    return p;//找到后返回该节点指针，否则返回NULL；
}

//求表长
int Length(LinkList L)
{
    int len=0;
    LNode*p=L;
    while(p->next!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}

//后插操作：在p节点后插入元素e
bool InsertNextNode(LNode* p,int e)
{
    if(p==NULL)//i值不合法
    return false;
    LNode *s =(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}


//前插操作
bool InsertPriorNode(LNode* p,int e)
{
    if(p==NULL)
    return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL)
    return false; //内存分配失败
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//在第i个位置插入元素e（带头结点）  (后插操作)
bool ListInsert(LinkList &L,int i,int e){
    if(i<1)
    return false;
    LNode* p;//指针指向的是当前扫描到的结点
    p=GetElem(L,i-1);
    if(p==NULL)
    return false;
   InsertNextNode(p,e);
}


//删除第i个结点
bool ListDelete(LinkList &L,int i,int &e)
{
    if(i<1)
    return false;
    LNode*p;//p指针指向的是当前扫描的结点
    p=GetElem(L,i-1);
    if(p==NULL)
    return false;
    if(p->next==NULL)
    return false;
    LNode *q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return true;
}

//删除指定结点
bool DeleteNode(LNode*p)
{
    if(p==NULL)
    return false;
    LNode*q=p->next;
    p->next->data=q->data;
    p->next=q->next;
    free(q);
    return true;
}



//打印链表元素
void printLinkList(LinkList &L)
{
    LNode* p;
    p=L;
    while(p!=NULL)
    {   
        printf("%d\n",p->data);
        p=p->next;
    }
}



void test()
{
    LinkList L;//声明一个指向单链表的指针

    //初始化一个空表
    InitList(L);
    
    //头插法建立单链表
     
    //插入一个元素
   // ListInsert(L,1,2);
    //
    List_HeadInsert(L);

    ListInsert(L,2,3);
    int e;
    ListDelete(L,3,e);
    printf("e=%d\n",e);
    //打印元素
    printLinkList(L);
    //打印表长
    printf("表长为：%d",Length(L));
}

int main()
{
    test();
    return 0;
}