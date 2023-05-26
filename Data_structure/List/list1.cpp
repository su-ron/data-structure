#include<stdio.h>
#include<stdlib.h>
//动态分配  
/*
 主要是理解
 L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));//这段代码的是动态地分配数组地内存空间
 然后第二个关键在于把原有数据复制到新开辟地内存空间中
*/
#define InitSize 10  //默认的最大长度

typedef struct {
    int *data;//指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length; //数组长度
}Seqlist;

//初始化一个顺序表
void InitList(Seqlist &L){
  //使用malloc函数申请一块连续的内存空间
  L.data=(int*)malloc(InitSize*sizeof(int));
  L.length=0;
  L.MaxSize=InitSize;
}

//增加动态数组的长度
void IncreaseSize(Seqlist&L,int len) //len就是需要增加数组的长度
{
  int *p=L.data;
  L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
  for(int i=0;i<L.length;i++){
    L.data[i]=p[i]; //将数据复制到新的内存空间，但是时间开销大
  }
  L.MaxSize=L.MaxSize+len;
  free(p);//释放原有数组内存空间
}

int main()
{
  Seqlist L;  //声明一个顺序表
  InitList(L);
  //往顺序表插入5个元素
  IncreaseSize(L,5);
  return 0;
}