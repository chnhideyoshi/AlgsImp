#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node
{
	T Data;
	struct Node *Next;
	Node()
	{
		Next=0;
	}
	Node(const T& data)
	{
		this->Data=data;
		Next=0;
	}
};
template<class T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList()
	{
		head=0;
	}
	~LinkedList()
	{
		while(DeleteHead()){}
	}
	inline Node<T>* Head()
	{
		return head;
	}
	inline Node<T>* Tail()
	{
		if(head==0)
			return 0;
		Node<T>* p=Head();
		while(p->Next!=0)
		{
			p=p->Next;
		}
		return p;
	}
	Node<T>* NodeAt(int index)
	{
		int i=0;
		Node<T>* p=Head();
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
		Node<T>* p=Head();
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
			Node<T>* p = this->head;
			this->head = this->head->Next;
			delete p;
			return true;
		}
	}
	bool DeleteTail()
	{
		if(head==0)
			return false;
		Node<T>* p=Head();
		Node<T>* pre=0;
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
			Node<T>* pre=NodeAt(index-1);
			if(pre==0||pre->Next==0)
				return false;
			else
			{
				Node<T>* temp=pre->Next->Next;
				Node<T>* del=pre->Next;
				pre->Next=temp;
				delete del;
				return true;
			}
		}
	}
	bool InsertBeforeHead(Node<T>* node)
	{
		Node<T>* p=Head();
		node->Next=p;
		this->head=node;
		return true;
	}
	bool InsertAfterTail(Node<T>* node)
	{
		if(head==0)
		{
			head=node;
			return true;
		}
		else
		{
			Node<T>* p=Tail();
			p->Next=node;
			node->Next=0;
			return true;
		}
	}
	bool InsertAfter(Node<T>* nodeToInsert,int index)
	{
		Node<T>* node=NodeAt(index);
		if(node==0)
		{
			return false;
		}
		Node<T>* temp=node->Next;
		node->Next=nodeToInsert;
		nodeToInsert->Next=temp;
		return true;
	}
	void Reverse()
	{
		int len=GetLength();
		if(len>=2)
		{
			Node<T>* p=head;
			Node<T>* pnext=p->Next;
			p->Next=0;
			while(pnext!=0)
			{
				Node<T>* ppnext=pnext->Next;
				pnext->Next=p;
				p=pnext;
				pnext=ppnext;
			}
			head=p;
		}
	}
	void Display()
	{
		printf("\n%d \n",GetLength());
		Node<T>* current=head;
		while(current!=0)
		{
			printf("%d ",current->Data);
			current=current->Next;
		}
	}
};

#endif
