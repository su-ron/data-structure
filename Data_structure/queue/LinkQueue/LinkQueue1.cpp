#include<stdio.h>
#include<stdlib.h>

//不带头结点

//队列的链式存储结构
typedef struct LinkNode{//链队列的结点
  int data;
  struct LinkNode*next;
}LinkNode;

typedef struct{  //链式队列
  struct LinkNode*front;
  struct LinkNode *rear;
}LinkQueue;

//初始化
void InitQueue(LinkQueue &Q)
{
    Q.front=NULL;
    Q.rear=NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    if(Q.front==NULL)
    return true;
    else
    return false;
}
//入队
void EnQueue(LinkQueue &Q,int e)
{
   LinkNode*p=(LinkNode*)malloc(sizeof(LinkNode));
   p->data=e;
   p->next=NULL;
   if(Q.front==NULL)//即在空队列插入第一个元素
   {
     Q.front=p;
     Q.rear=p;
   }
   else
   {
    Q.rear->next=p; //新结点插入到rear结点之后
    Q.rear=p;
   }

}

//出队
bool DeQueue(LinkQueue&Q,int e)
{
   if(Q.front==NULL)
   return false;
   LinkNode *p=Q.front;//p指向队的结点
   e=p->data;
   Q.front=p->next; //修改front指针
   if(Q.rear==p){ //此次是最后一个结点出队
     Q.rear=NULL;
     Q.front=NULL;
   }
  free(p);
  return true;
}

//获得队头元素的值，用x返回
bool GetHead(LinkQueue &Q,int x)
{
    if(Q.rear==Q.front)
    return false;
    x=Q.front->data;
    return true;
}
//打印
void print(LinkQueue Q)
{
   LinkNode*p;
   p=Q.front;
   while(p!=Q.rear)
   {
    p=p->next;
    printf("%d\n",p->data);
   }
    
}
void test()
{
  LinkQueue Q;
  InitQueue(Q);
  EnQueue(Q,10);
  EnQueue(Q,20);
  EnQueue(Q,30);
  print(Q);
  printf("-----------------------\n");
  int e;
  DeQueue(Q,e);
  print(Q);
}


int main()
{
    test();
    return 0;
}