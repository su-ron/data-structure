#include<stdio.h>
#include<stdlib.h>

//带头结点

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
    Q.rear=Q.front=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

//入队
void EnQueue(LinkQueue &Q,int e)
{
   LinkNode*p=(LinkNode*)malloc(sizeof(LinkNode));
   p->data=e;
   p->next=NULL;
   Q.rear->next=p; 
   Q.rear=p;
}

//出队
bool DeQueue(LinkQueue&Q,int e)
{
  if(Q.front==Q.rear)
  return false;
  LinkNode*p;
  p=Q.front->next;
  e=p->data;
  Q.front->next=p->next;//修改头结点的next指针
  if(Q.rear==p)         //此次是最后一个结点出队
    Q.rear=Q.front;     //修改结点空间
  free(p);              //释放结点空间
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