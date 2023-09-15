#pragma once
#include "Array.h"

DynamicArray GetObj() 
{
	DynamicArray obj(3);
	obj.Input();
	return obj;
}

void main()
{
	DynamicArray a(5);
	a.Input();
	a.Output();

	int foundIndex = a.Search(1);
	cout << "Index = " << foundIndex << endl;
	a.Sort();
	a.Output();
	a.Reverse();
	a.Output();
	a.ReSize(10);
	a.Input();
	a.Output();

	system("pause");
}