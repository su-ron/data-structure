#include<stdio.h>
#include<stdlib.h>

//双链表
typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinklist;

//初始化双链表
bool InitDLinkList(DLinklist &L){
    L=(DNode*)malloc(sizeof(DNode));//分配头结点
    if(L==NULL)  //内存不足，分配失败
    return false;
    L->prior=NULL;//头结点的prior永远指向NULL
    L->next=NULL; //头结点之后暂时没有节点
    return true;
}

//双链表的插入
//在p结点后插入s结点
bool InsertNextDNode(DNode *p,DNode *s)
{
    if(p==NULL||s==NULL)
    return false;
    s->next=p->next;
    if(p->next!=NULL)
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}
//删除p结点的后继结点
bool DeleteNextDNode(DNode*p){
    if(p==NULL) return false;
    DNode* q=p->next; //找到p的后继结点
    if(q==NULL) return false;
    p->next=q->next;
    if(q->next!=NULL) //q结点不是最后一个结点
    q->next->prior=p;
    free(q);  //释放结点空间
    return true;
}
//双链表的删除
void DestoryList(DLinklist &L)
{
    //循环释放各个数据结点
    while(L->next!=NULL)
    DeleteNextDNode(L);
    free(L);//释放头结点
    L=NULL; //头指针指向NULL
}

//头插法建立双链表
DLinklist DLlist_TailInsert(DLinklist &L)
{
    int x;    //数据为整形
    L=(DLinklist)malloc(sizeof(DNode));//建立头结点
    DNode*s;
    L->next=NULL;
    L->prior=NULL;
    printf("请输入节点的值(输入9999表示结束):");
    scanf("%d",&x);  //输入节点的值
    while(x!=9999){//输入9999表示结束
      s=(DNode*)malloc(sizeof(DNode));//创建新节点
      s->data=x;
      InsertNextDNode(L,s);
    printf("请输入节点的值(输入9999表示结束):");
    scanf("%d",&x);  //输入节点的值  
    }
   return L;
}

//打印链表元素
void printLinkList(DLinklist &L)
{
    DNode* p;
    p=L;
    while(p!=NULL)
    {   
        printf("%d\n",p->data);
        p=p->next;
    }
}

void testDLinkList(){  //判断双链表是否为空（带头结点）
   //初始化
   DLinklist L;
   InitDLinkList(L);
   //头插法建立双链表
   DLlist_TailInsert(L);
   printLinkList(L);
   DestoryList(L);
   
}

int main()
{
    testDLinkList();
    return 0;
}