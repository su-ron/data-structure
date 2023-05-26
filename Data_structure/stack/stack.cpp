#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10  //定义栈中元素的最大个数

typedef struct{
    int data[MaxSize]; //静态数组存放栈中元素
    int top;//栈顶指针存放元素
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
    S.top=-1;//初始化栈顶指针
}

//判断栈空
bool StackEmpty(SqStack S){
    if(S.top==-1)   //栈空
    return true;
    else            //不空
    return false;
}

//新元素进栈
bool Push(SqStack &S,int x)
{
    if(S.top=MaxSize-1)
    return false;
    S.top=S.top+1;//指针先加1
    S.data[S.top]=x;//新元素入栈
    return true;
}

//出栈操作
bool POP(SqStack &S,int x)
{
    if(S.top==-1)
    return false;
    x=S.data[S.top];
    S.top--;
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,int &x)
{
    if(S.top==-1)
    return false;
    x=S.data[S.top];
    return true;
}

void printStack(SqStack &S)
{
    int x=0;
    while(x!=S.top)
    {
        printf("%d\n",S.data[x]);
        x++;
    }
}

void testStack(){
    SqStack S;//声明一个顺序栈（分配空间）
    InitStack(S);
   
    Push(S,1);
    Push(S,9);
    Push(S,1);
    printStack(S);
}

int main()
{
    testStack();
    return 0;
}