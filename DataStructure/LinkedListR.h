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
	NodeR(const T& v)
	{
		Data=v;
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
	inline NodeR<T>* Tail()
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
		if(Head() == 0)
		{
			return false;
		}
		else
		{
			if(this->head->Next==0)
			{
				delete head;
				head=0;
				return true;
			}
			else
			{
				NodeR<T>* p = this->head;
				this->head = p->Next;
				this->head->Prev=0;
				delete p;
				return true;
			}
		}
	}
	bool DeleteTail()
	{
		if(head==0)
			return false;
		NodeR<T>* p=Head();
		NodeR<T>* pre=0;
		while(p->Next!=0)
		{
			pre=p;
			p=p->Next;
		}
		delete p;
		pre->Next=0;
		return true;
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
		return true;
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
			node->Prev=p;
			node->Next=0;
			return true;
		}
	}
	bool InsertAfter(NodeR<T>* nodeToInsert,int index)
	{
		NodeR<T>* node=NodeAt(index);
		if(node==0)
		{
			return false;
		}
		NodeR<T>* pnext=node->Next;
		node->Next=nodeToInsert;
		nodeToInsert->Next=pnext;
		nodeToInsert->Prev=node;
		pnext->Prev=nodeToInsert;
		return true;
	}
	void Reverse()
	{
		NodeR<T>* current=head;
		while(current!=0)
		{
			NodeR<T>* temp=current->Prev;
			current->Prev=current->Next;
			current->Next=temp;
			if(current->Prev==0)
				head=current;
			current=current->Prev;
		}
	}
	void Display()
	{
		printf("\n%d \n",GetLength());
		NodeR<T>* current=head;
		while(current!=0)
		{
			printf("%d ",current->Data);
			current=current->Next;
		}
	}
};
template<class T>
class LinkedListC
{
private:
	NodeR<T>* head;
public:
	LinkedListC()
	{
		head=0;
	}
	~LinkedListC()
	{
		while(DeleteHead()){}
	}
	inline NodeR<T>* Head()
	{
		return head;
	}
	inline NodeR<T>* Tail()
	{
		if(head==0)
			return 0;
		return head->Prev;
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
		while(p!=head)
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
		if(Head() == 0)
		{
			return false;
		}
		else
		{
			NodeR<T>* p = this->head;
			this->head = this->head->Next;
			this->head->Prev=p->Prev;
			delete p;
			return true;
		}
	}
	bool DeleteTail()
	{
		if(head==0)
			return false;
		NodeR<T>* p=Tail();
		p->Prev->Next=head;
		head->Prev=p->Prev;
		delete p;
		return true;
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
		return true;
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
			node->Prev=p;
			node->Next=head;
			head->Prev=node;
			return true;
		}
	}
	bool InsertAfter(NodeR<T>* nodeToInsert,int index)
	{
		NodeR<T>* node=NodeAt(index);
		if(node==0)
		{
			return false;
		}
		NodeR<T>* pnext=node->Next;
		node->Next=nodeToInsert;
		nodeToInsert->Next=pnext;
		nodeToInsert->Prev=node;
		pnext->Prev=nodeToInsert;
		return true;
	}
	void Reverse()
	{
		NodeR<T>* current=head;
		while(current!=head)
		{
			NodeR<T>* temp=current->Prev;
			current->Prev=current->Next;
			current->Next=temp;
			current=current->Prev;
		}
	}
	void Display()
	{
		if(head==0)
			return;
		printf("\n%d \n",GetLength());
		NodeR<T>* current=head;
		if(head->Next!=head)
		{
			while(current!=head)
			{
				printf("%d ",current->Data);
				current=current->Next;
			}
		}
		else
		{
			printf("%d ",head->Data);
		}
		
	}
};
#endif