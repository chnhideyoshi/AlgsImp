#ifndef TREE_H
#define TREE_H
#define DataType int
#include <queue>

struct TreeNode
{
	DataType Data;
	TreeNode* Parent;
	TreeNode* LChild;
	TreeNode* RChild;
	TreeNode(DataType value)
	{
		this->Data=value;
		this->Parent=0;
		this->LChild=0;
		this->RChild=0;
	}
};
enum TravelMethod
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
			root=new TreeNode(value);
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
				p->LChild=new TreeNode(value);
			else
			    p->RChild=new TreeNode(value);
		}
	}
	void Delete(DataType value)
	{

	}
	void Travel(TravelMethod method,void (*Process)(TreeNode* node))
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
private:
	static void Print(TreeNode* node)
	{
		printf("node: %d,",node->Data);
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
			PreOrderTraversal(node->LChild);
		}
		Action(node);
		if(node->RChild!=0)
		{
			PreOrderTraversal(node->RChild);
		}
	}
	void PostOrderTraversal(TreeNode* node)
	{
		if(node->LChild!=0)
		{
			PreOrderTraversal(node->LChild);
		}
		if(node->RChild!=0)
		{
			PreOrderTraversal(node->RChild);
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
};

#endif