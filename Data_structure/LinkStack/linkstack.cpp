#include<stdio.h>
#include<stdlib.h>

//链栈的表示
typedef struct StackNode{
    int data; //数据域
    struct StackNode *next;//指针域
}StackNode,*LinkStack;//栈类型定义

//链栈的初始化
int InitStack(LinkStack &S)
{
    S=NULL;
    return 1;
}

//链栈进栈
int Push(LinkStack &S,int e)
{
   StackNode*p;
   p=new StackNode;
   p->data=e;
   p->next=S;//把新结点插入栈顶
   S=p; //修改栈顶指针
   return 1;
}

//链栈出栈
int Pop(LinkStack&S,int e)
{
    if(S==NULL)
    return false;
    e=S->data;//栈顶元素赋给e
    StackNode*p;//临时保存栈顶元素的空间，以备释放
    p=S;
    S=S->next;//修改栈顶指针
    delete(p);
    return 1;
}

//取栈顶元素
int GetTop(LinkStack&S)
{
    if(S!=NULL)
    return S->data;
}

//打印链栈元素
void print(LinkStack&S)
{
    StackNode*p;
    p=S;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void test()
{
   LinkStack S;
   InitStack(S);
   Push(S,10);
   Push(S,20);
   Push(S,30);
   print(S);
   printf("---------------\n");
   int e;
   Pop(S,e);
   print(S);
}

int main()
{
    test();
    return 0;
}