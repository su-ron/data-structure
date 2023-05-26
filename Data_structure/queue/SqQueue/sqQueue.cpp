#include<stdio.h>
#include<stdlib.h>

//队列的顺序存储结构
#define MaxSize 10  //定义队列中元素的最大个数
typedef struct{
    int data[MaxSize];  //用静态数组存放队列元素
    int front,rear;  //队头指针和队尾指针
} SqQueue;


//初始化队列
void InitQueue(SqQueue &Q){
    //初始化时,队头,队尾指向0
    Q.rear=Q.front=0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
    return true;//队空
    else
    return false;
}

//入队操作
bool EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MaxSize==Q.front)
    return false;//队列已满；该种方法需要牺牲队列的一个存储空间
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)% MaxSize;
    return true;
}

//出队操作 先进先出
bool DeQueue(SqQueue &Q,int&e)
{
    if(Q.front==Q.rear)//队空
    return false;
    e=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

//获得队头元素的值，用x返回
bool GetHead(SqQueue Q,int x)
{
    if(Q.rear==Q.front)
    return false;
    x=Q.data[Q.front];
    return true;
}

void print(SqQueue Q)
{
    int ptr=Q.front;
    if(Q.rear!=Q.front)
    {
      while((ptr)!=Q.rear)
    {
        printf("%d\n",Q.data[ptr]);
        ptr++;
    }
    }

}
void test()
{
  SqQueue Q;
  InitQueue(Q);
  EnQueue(Q,10);
  EnQueue(Q,20);
  EnQueue(Q,50);
  print(Q);
  int e;
  DeQueue(Q,e);
  printf("-----------------------\n");
    print(Q);
}

int main()
{
  test();
}