#include"sqlist1.h"

int main()
{
	int a[30] = { 1,2,3,4,5,6,7,8,9,0,10 };
	LinkList<int> L(a, 10); 
		cout << "���Ա��Ԫ�أ�" << endl;
	L.print();
	cout << "���Ա����һ��Ԫ��" << endl;
	L.Insert(8, 2);
	L.print();
	L.SetValue(5, 9);
	L.print();
	int i=L.Locate(8);
	cout << "i=" << i << endl;


	return 0;
}
