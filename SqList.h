using namespace std;

const int MAXSIZE = 100;
template<class T>

class SqList
{
	T data[MAXSIZE];
	int length;

public:
	SqList()
	{
		length = 0;
	}

	SqList(const T a[], int n);//初始化线性表
	bool  ListEmpty();//判断线性表是否为空
	//void  ClearList(Sqlist &sqlist);
	bool ListInsert(int i, T a);//插入参数
	bool ListDelete(int i);//删除元素
	int ListLength();//获取线性表长度
	void print();//打印
	bool SetValue(int i, T a);//给线性表某一位设值
	T GetElem(int i);//获取元素
	int Locate(T a);//定位元素
};

template<class T>
SqList<T>::SqList(const T a[], int n)
{
	if (n > MAXSIZE)
		throw"超出顺序表最大长度";
	else
		for (int i = 0; i < n; i++)
		{
			data[i] = a[i];
		}
	length = n;
}

template<class T>
bool SqList<T>::ListEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

template<class T>
bool  SqList<T>::ListInsert(int i, T a)
{
	int k;
	if (length == MAXSIZE)
		return false;
	if (i<1 || i>length + 1)
		return false;
	if (i < length)
	{
		for (k = length-1; k < i - 1; k--)
		{
			data[k + 1] = data[k];
		}
		data[i] = a;
		length++;
		return true;
	}
}

template<class T>
bool SqList<T>::ListDelete(int i)
{
	int k;
	if (length == 0)
		return false;
	if (i<1 || i>length)
		return false;
	if (i < length&&i>0)
	{
		for (k = i; k < length; k++)
		{
			data[k] = data[k + 1];
		}
		length--;
	}
}

template<class T>
int SqList<T>::ListLength()
{
	return length;
}

template<class T>
void SqList<T>::print()
{

	cout << "顺序表的各个元素如下：" << endl;
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<class T>
bool SqList<T>::SetValue(int i, T a)
{
	if (i<1 || i>length)
		return false;
	else
	{
		data[i - 1] = a;
		return true;
	}
}

template<class T>
T SqList<T>::GetElem(int i)
{
	if (i<0 || i>length || length == 0)
		return false;
	else
	 return data[i - 1];
}

template<class T>
int SqList<T>::Locate(T a);//定位元素



#pragma once
