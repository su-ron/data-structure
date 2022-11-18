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

	SqList(const T a[], int n);//��ʼ�����Ա�
	bool  ListEmpty();//�ж����Ա��Ƿ�Ϊ��
	//void  ClearList(Sqlist &sqlist);
	bool ListInsert(int i, T a);//�������
	bool ListDelete(int i);//ɾ��Ԫ��
	int ListLength();//��ȡ���Ա���
	void print();//��ӡ
	bool SetValue(int i, T a);//�����Ա�ĳһλ��ֵ
	T GetElem(int i);//��ȡԪ��
	int Locate(T a);//��λԪ��
};

template<class T>
SqList<T>::SqList(const T a[], int n)
{
	if (n > MAXSIZE)
		throw"����˳�����󳤶�";
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

	cout << "˳���ĸ���Ԫ�����£�" << endl;
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
int SqList<T>::Locate(T a);//��λԪ��



#pragma once
