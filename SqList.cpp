#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"SqList.h"
using namespace std;

int main(int argc, char**argv)
{
	int a[30] = { 1,2,3,4,5,6,7,8,9,0,10 };
	SqList<int> L(a, 20);
	L.print();
	L.SetValue(10, 1);
	L.print();
	L.ListInsert(11, 5);
	L.print();
	L.ListDelete(2);
	L.print();
	int i;
	i=L.ListLength();
	cout << "i=" << i << endl;


	return 0;
}