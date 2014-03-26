#ifndef MERGESORT_H
#define MERGESORT_H 

template<class T>
class MergeSorter
{
private:
	T* array;
	int count;
	T* temp;
public:
	MergeSorter(T* array, int count)
	{
		this->array=array;
		this->count=count;
		this->temp=new T[count];
	}
	~MergeSorter()
	{}
	void Sort()
	{
		Sort(0,count-1);
	}
private:
	void Sort(int st,int ed)
	{
		if(st==ed)
			return;
		else
		{
			int mid=(st+ed)>>1;
			Sort(st,mid);
			Sort(mid+1,ed);
			Merge(st,mid,ed);
		}
	}
	void Merge(int st,int mid,int ed)
	{
		int p0=st;
		int p1=mid+1;
		int index=st;
		while(p0<=mid&&p1<=ed)
		{
			if(array[p0]<array[p1])
			{
				temp[index]=array[p0];
				p0++;
			}
			else
			{
				temp[index]=array[p1];
				p1++;
			}
			index++;
		}
		if(p0==mid+1&&p1<=ed)
		{
			memcpy(temp+index,array+p1,sizeof(T)*(ed-p1+1));
		}
		else if(p1==ed+1&&p0<=mid)
		{
			memcpy(temp+index,array+p0,sizeof(T)*(ed-p0+1));
		}
		memcpy(array+st,temp+st,sizeof(T)*(ed-st+1));
	}
};


#endif