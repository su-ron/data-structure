#include<stdio.h>
#
//静态分配
#define MaxSize 10  //定义最大长度

typedef struct {
    int data[MaxSize];//使用静态数组存放元素
    int length; //数组长度
}Sqlist;

//初始化一个顺序表
void InitList(Sqlist &L){
   for(int i=0;i<MaxSize;i++)
    L.data[i]=0;
    L.length=0;
}
//插入元素
bool ListInsert(Sqlist &L,int i,int e)//顺序表插入,i表示插入位置，e表示插入元素
{
  if(i<1||i>L.length+1)  //判断i是否有效
   return false;
   if(L.length>=MaxSize)  //当前存储空间已满，不能插入
   return false;
  for(int j=L.length;j>=i;j--)
    L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
  return true;
}
//删除元素
bool ListDelete(Sqlist &L,int i,int &e)
{
   if(i<1||i>L.length+1)  //判断i是否有效
   return false;
   e=L.data[i-1];
   for(int j=i;j<L.length;j++)
   L.data[j-1]=L.data[j];
   L.length--;
   return true;
}

//顺序表按位查找
int GetElem(Sqlist L,int i)
{
  return L.data[i-1];
}
//顺序表按值查找
//存在问题，如果顺序表中不同位置有相同的数据，返回值应该如何接收
int LocateElem(Sqlist L,int e)
{
  for(int i=0;i<L.length;i++)
      for(i=0;i<L.length;i++)
      if(L.data[i]==e)
      return i+1;
   return 0;
}

//元素打印
void printList(Sqlist&L)
{
  for(int i=0;i<MaxSize;i++)
  printf("%d",L.data[i]);
  printf("\n");
}

int main()
{
  Sqlist L;  //声明一个顺序表
  InitList(L);
  ListInsert(L,1,1);
  ListInsert(L,2,1);
  ListInsert(L,3,2);
  printList(L);

  printf("%d",LocateElem(L,1));
  int e=-1;
  ListDelete(L,1,e);
  printf("e=%d\n",e);
  printList(L);
  return 0;
}