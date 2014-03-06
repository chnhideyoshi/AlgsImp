#ifndef TREE_H
#define TREE_H
#include <queue>

struct TreeNode
{
	DataType Data;
	TreeNode* Parent;
	TreeNode* LChild;
	TreeNode* RChild;
	TreeNode(DataType value,TreeNode* parent)
	{
		this->Data=value;
		this->Parent=parent;
		this->LChild=0;
		this->RChild=0;
	}
};
enum TreeTravelMethod
{
	PreOrder=0,
	InOrder=1,
	PostOrder=2,
	BreadthFirst=3,
};
class BinarySearchTree
{
private:
	TreeNode* root;
	void (*Action)(TreeNode* node);
public:
	BinarySearchTree()
	{
		root=0;
	}
	void Insert(DataType value)
	{
		if(root==0)
		{
			root=new TreeNode(value,0);
			return;
		}
		else
		{
			TreeNode* node=root;
			TreeNode* p=0;
			bool left=false;
			while(node!=0)
			{
				if(value>node->Data)
				{
					p=node;
					left=false;
					node=node->RChild;
				}
				else
				{
					p=node;
					left=true;
					node=node->LChild;
				}
			}
			if(left)
				p->LChild=new TreeNode(value,p);
			else
			    p->RChild=new TreeNode(value,p);
		}
	}
	bool Delete(DataType value)
	{
	     TreeNode* node=Search(value);
		 if(node!=0)
		 {
			 DeleteNode(node);
			 return true;
		 }
		 else
			 return false;
	}
	void Travel(TreeTravelMethod method,void (*Process)(TreeNode* node))
	{
		if(Process==0||root==0)
			return;
		this->Action=Process;
		if(method==PreOrder)
			PreOrderTraversal(root);
		if(method==InOrder)
			InOrderTraversal(root);
		if(method==PostOrder)
			PostOrderTraversal(root);
		if(method==BreadthFirst)
			BreadthFirstTraversal(root);
		this->Action=0;
	}
	void Display()
	{
		Travel(BreadthFirst,Print);
	}
    bool Exist(DataType value)
	{
		TreeNode* node=Search(value);
		return node!=0;
	}
	DataType GetMin()
	{
		return GetMinNode(root)->Data;
	}
	DataType GetMax()
	{
		return GetMaxNode(root)->Data;
	}
	DataType GetPredecessor(DataType value)
	{
		TreeNode* node=Search(value);
		if(node==0)
			throw std::exception();
		TreeNode* p=GetPredecessorNode(node);
		if(p!=0)
			return p->Data;
		else
			throw new std::exception();
	}
	DataType GetSuccessor(DataType value)
	{
		TreeNode* node=Search(value);
		if(node==0)
			throw std::exception();
		TreeNode* p=GetSuccessorNode(node);
		if(p!=0)
			return p->Data;
		else
			throw new std::exception();
	}
private:
	bool IsLChild(TreeNode* node)
	{
		return node->Parent->LChild==node;
	}
	bool IsRChild(TreeNode* node)
	{
		return node->Parent->RChild==node;
	}
	void DeleteNode(TreeNode* node)
	{
		if(node->LChild==0&&node->RChild==0)
		{
			if(node==root)
			{
				delete root;
				root=0;
			}
			else if(IsLChild(node))
			{
				node->Parent->LChild=0;
				delete node;
			}
			else
			{
				node->Parent->RChild=0;
				delete node;
			}
		}
		else if(node->LChild==0&&node->RChild!=0)
		{
			if(IsLChild(node))
			{
				node->Parent->LChild=node->RChild;
				node->RChild->Parent=node->Parent;
				delete node;
			}
			else
			{
				node->Parent->RChild=node->RChild;
				node->RChild->Parent=node->Parent;
				delete node;
			}
		}
		else if(node->LChild!=0&&node->RChild==0)
		{
			if(IsLChild(node))
			{
				node->Parent->LChild=node->LChild;
				node->LChild->Parent=node->Parent;
				delete node;
			}
			else
			{
				node->Parent->RChild=node->LChild;
				node->LChild->Parent=node->Parent;
				delete node;
			}
		}
		else
		{
			TreeNode* suc=GetSuccessorNode(node);
			node->Data=suc->Data;
			DeleteNode(suc);
		}
	}
	TreeNode* Search(DataType value)
	{
		TreeNode* node=root;
		while(node!=0)
		{
			if(node->Data==value)
				return node;
			else if(node->Data<value)
				node=node->RChild;
			else
				node=node->LChild;
		}
		return 0;
	}
	TreeNode* GetPredecessorNode(TreeNode* node)
	{
		if (node->LChild != 0)  
			return GetMaxNode(node->LChild);  
		TreeNode* y = node->Parent;  
		while (y != NULL && node == y->LChild)  
		{  
			node = y;  
			y = y->Parent;  
		}  
		return y;  
	}
	TreeNode* GetSuccessorNode(TreeNode* node)
	{
		if (node->RChild != 0)  
			return GetMinNode(node->RChild);  
		TreeNode* y = node->Parent;  
		while (y != NULL && node == y->RChild)  
		{  
			node = y;  
			y = y->Parent;  
		}  
		return y;  
	}
	TreeNode* GetMinNode(TreeNode* node)
	{
		if(node==0)
			throw std::exception();
		TreeNode* p = node;  
		while (p->LChild != 0)  
			p = p->LChild;  
		return p;  
	}
	TreeNode* GetMaxNode(TreeNode* node)
	{
		if(node==0)
			throw std::exception();
		TreeNode* p = node;  
		while (p->RChild != 0)  
			p = p->RChild;  
		return p;  
	}
	void PreOrderTraversal(TreeNode* node)
	{
		Action(node);
		if(node->LChild!=0)
		{
			PreOrderTraversal(node->LChild);
		}
		if(node->RChild!=0)
		{
			PreOrderTraversal(node->RChild);
		}
	}
	void InOrderTraversal(TreeNode* node)
	{
		if(node->LChild!=0)
		{
			InOrderTraversal(node->LChild);
		}
		Action(node);
		if(node->RChild!=0)
		{
			InOrderTraversal(node->RChild);
		}
	}
	void PostOrderTraversal(TreeNode* node)
	{
		if(node->LChild!=0)
		{
			PostOrderTraversal(node->LChild);
		}
		if(node->RChild!=0)
		{
			PostOrderTraversal(node->RChild);
		}
		Action(node);
	}
	void BreadthFirstTraversal(TreeNode* node)
	{
		std::queue<TreeNode*> q;
		q.push(node);
		Action(node);
		while(!q.empty())
		{
			TreeNode* t=q.front();
			q.pop();
			if(t->LChild!=0)
			{
				Action(t->LChild);
				q.push(t->LChild);
			}
			if(t->RChild!=0)
			{
				Action(t->RChild);
				q.push(t->RChild);
			}
		}
	}
public:
	 static void Print(TreeNode* node)
	{
		printf("%d,",node->Data);
	}
};

#endif