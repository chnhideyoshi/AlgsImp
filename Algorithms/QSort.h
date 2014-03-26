#ifndef  QSORT_H
#define QSORT_H

template<class T>
class QSorter
{
private:
	T* array;
	int count;
public:
	QSorter(T* array,int count)
	{
		this->array=array;
		this->count=count;
	}
	~QSorter()
	{

	}
	void Sort()
	{
		Qsort(0,count-1);
	}
private:
	int Partition(int st,int ed,int pos)
	{
		T value=array[pos];
		Swap(st,pos);
		int bound=st;
		for(int i=st+1;i<=ed;i++)
		{
			if(array[i]<value)
			{
				Swap(i,bound+1);
				bound++;
			}
		}
		Swap(st,bound);
		return bound;
	}
	void Qsort(int st,int ed)
	{
		if(st>=ed)
			return;
		else
		{
			int mid=Partition(st,ed,st);
			Qsort(st,mid-1);
			Qsort(mid+1,ed);
		}
	}
	void Swap(int i,int j)
	{
		T temp=array[i];
		array[i]=array[j];
		array[j]=temp;
	}
};

#endif