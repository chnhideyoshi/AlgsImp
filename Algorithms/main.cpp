#include <iostream>
#include "QSort.h"
#include "MergeSort.h"

void TestQSort()
{
	int a[10]={5,3,2,1,0,9,7,6,4,8};
	QSorter<int> q(a,10);
	q.Sort();
	for(int i=0;i<10;i++)
		printf("%d,",a[i]);
}
void TestMergeSort()
{
	int a[10]={5,3,2,1,0,9,7,6,4,8};
	MergeSorter<int> q(a,10);
	q.Sort();
	for(int i=0;i<10;i++)
		printf("%d,",a[i]);
}


int main()
{
	TestMergeSort();
	system("pause");
	return 0;
}