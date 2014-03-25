#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <typeinfo>
template<class T,class V>
class HashTable_LinkedList
{
private:
	struct LinkListNode
	{
		T Key;
		V Value;
		LinkListNode* Next;
		LinkListNode(T key,V value,LinkListNode* next=0)
		{
			this->Key=key;
			this->Value=value;
			this->Next=next;
		}
	};
private:
	static const int TableSize=10000;
	LinkListNode**Table;
public:
	HashTable_LinkedList()
	{
		Table=new LinkListNode*[TableSize];
		memset(Table,0,TableSize*sizeof(LinkListNode*));
	}
	~HashTable_LinkedList()
	{
		for(int i=0;i<TableSize;i++)
		{
			if(Table[i]!=0)
			{
				ReleaseLinkList(i);
			}
		}
		delete[] Table;
	}
	void SetValue(T key,V value)
	{
		int index=CalculateHash(key);
		if(Table[index]==0)
		{
			Table[index]=new LinkListNode(key,value,0);
		}
		else
		{
			LinkListNode* cur=Table[index];
			if(cur->Key==key)
			{
				cur->Value=value;
				return;
			}
			while(cur->Next!=0)
			{
				if(cur->Next->Key==key)
				{
					cur->Next->Value=value;
					return;
				}
				cur=cur->Next;
			}
			cur->Next=new LinkListNode(key,value);
		}
	}
	V GetValue(T key)
	{
		int index=CalculateHash(key);
		LinkListNode* node=Search(index,key);
		if(node==0)
			throw std::exception();
		else
			return node->Value;
	}
	void DeleteKey(T key)
	{
		int index=CalculateHash(key);
		LinkListNode* cur=Table[index];
		if(cur->Key==key)
		{
			DeleteHead(index);
			return;
		}
		while(cur->Next!=0)
		{
			if(cur->Next->Key==key)
			{
				DeleteNodeAfter(cur);
				return;
			}
			cur=cur->Next;
		}
	}
	bool Exist(T key)
	{
		int index=CalculateHash(key);
		LinkListNode* node=Search(index,key);
		return node!=0;
	}
private:
	LinkListNode* Search(int index,T key)
	{
		LinkListNode* cur=Table[index];
		while(cur!=0)
		{
			if(cur->Key==key)
			{
				return cur;
			}
			cur=cur->Next;
		}
		return 0;
	}
	LinkListNode* FindTail(int index)
	{
		LinkListNode* cur=Table[index];
		while(cur->Next!=0)
		{
			cur=cur->Next;
		}
		return cur;
	}
	void ReleaseLinkList(int index)
	{
		while(Table[index]!=0)
		{
			DeleteHead(index);
		}
	}
	void DeleteHead(int index)
	{
		if(Table[index]->Next!=0)
		{
			LinkListNode* temp=Table[index];
			Table[index]=Table[index]->Next;
			delete temp;
		}
		else
		{
			delete Table[index];
			Table[index]=0;
		}
	}
	void DeleteNodeAfter(LinkListNode* prev)
	{
		if(prev->Next!=0)
		{
			LinkListNode* node=prev->Next;	
			prev->Next=prev->Next->Next;
			delete node;
		}
	}
protected:
	int CalculateHash(T key)
	{
		/*printftypeid(key).name)*/
		return key%TableSize;
	}
};

#endif