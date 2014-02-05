#ifndef LINKEDLISTR_H
#define LINKEDLISTR_H

template<class T>
struct NodeR
{
	T Data;
	struct NodeR *Next;
	struct NodeR *Prev;
	NodeR()
	{
		Next=0;
		Prev=0;
	}
};

template<class T>
class LinkedListR
{
private:
	NodeR<T>* head;
public:
	LinkedListR()
	{
		head=0;
	}
	~LinkedListR()
	{
		while(DeleteHead()){}
	}
	inline NodeR<T>* Head()
	{
		return head;
	}
	inline Node<T>* Tail()
	{
		if(head==0)
			return 0;
		NodeR<T>* p=Head();
		while(p->Next!=0)
		{
			p=p->Next;
		}
		return p;
	}
	NodeR<T>* NodeAt(int index)
	{
		int i=0;
		NodeR<T>* p=Head();
		while(i!=index&&p!=0)
		{
			i++;
			p=p->Next;
		}
		return p;
	}
	int GetLength()
	{
		int len=0;
		NodeR<T>* p=Head();
		while(p!=0)
		{
			len++;
			p=p->Next;
		}
		return len;
	}
	bool IsEmpty()
	{
		return Head()==0;
	}
	bool DeleteHead()
	{
		if(Head() == NULL)
		{
			return false;
		}
		else
		{
			NodeR<T>* p = this->head;
			this->head = this->head->Next;
			this->head->Prev=0;
			delete p;
			return true;
		}
	}
	bool DeleteTail()
	{
		if(tail==0)
			return false;
		else
		{
			NodeR<T>* p=tail->Prev;
			p->Next=0;
			delete tail;
			this->tail=p;
			return true;
		}
		
	}
	bool DeleteAt(int index)
	{
		if(index==0)
			return DeleteHead();
		else
		{
			NodeR<T>* p=NodeAt(index);
			if(p==0)
				return false;
			else
			{
				NodeR<T>* pre=p->Prev;
				NodeR<T>* pnext=p->Next;
				pre->Next=pnext;
				pnext->Prev=pre;
				delete p;
				return true;
			}
		}
	}
	bool InsertBeforeHead(NodeR<T>* node)
	{
		NodeR<T>* p=Head();
		node->Next=p;
		p->Prev=node;
		this->head=node;
	}
	bool InsertAfterTail(NodeR<T>* node)
	{
		if(head==0)
		{
			head=node;
			head->Prev=0;
			head->Next=0;
			return true;
		}
		else
		{
			NodeR<T>* p=Tail();
			p->Next=node;
			node->Next=0;
			return true;
		}
	}
	bool InsertAfter(NodeR<T>* nodeToInsert,int index)
	{
		NodeR<T>* node=NodeAt(index);
		if(node==null)
		{
			return false;
		}
		NodeR<T>* temp=node->Next;
		node->Next=nodeToInsert;
		nodeToInsert->Next=temp;
		return true;
	}
	void Reverse()
	{
		int len=GetLength();
		if(len>=2)
		{
			NodeR<T>* pre=head;
			NodeR<T>* p=pre->Next;
			NodeR<T>* pnext=p->Next;
			head->Next=0;
			while(pnext!=0)
			{
				p->Next=pre;
				pre=p;
				p=pnext;
				pnext=pnext->Next;
			}
			head=p;
		}
	}
};

#endif