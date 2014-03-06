#ifndef GRAPH_H
#define GRAPH_H
#include <queue>
enum GraphTravelMethod
{
	MDepthFirst=0,
	MBreadthFirst=1,
};
class UndirectedGraphBase
{
protected:
	DataType* Data;
	bool* visitFlag;
	void (*Action)(DataType value);
public:
	virtual bool HasEdge(int index0,int index1)=0;
	virtual int GetEdgeCount()=0;
	virtual int GetVertexCount()=0;
	virtual int GetNeighbours(int* neighbourIndices,int nodeIndex)=0;
	virtual void AddEdge(int index0,int index1)=0;
	virtual void DeleteEdge(int index0,int index1)=0;
	virtual void AddVertex(DataType value)=0;
	virtual void Travel(int startIndex,GraphTravelMethod method,void (*Process)(DataType value))=0;
public:
	static void Print(DataType data)
	{
		printf("%d,",data);
	}
};
class  UndirectedGraph_Matrix:public UndirectedGraphBase
{
private:
	int maxVertexSize;
	int vertexCount;
	int edgeCount;
	int* relationMap;
public:
	UndirectedGraph_Matrix(int maxVertexSize)
	{
		this->maxVertexSize=maxVertexSize;
		this->relationMap=new int[maxVertexSize*maxVertexSize];
		this->Data=new DataType[maxVertexSize];
		this->vertexCount=0;
		this->edgeCount=0;
		memset(relationMap,0,sizeof(int));
		this->visitFlag=0;
	}
	~UndirectedGraph_Matrix()
	{
		delete[] relationMap;
		delete[] Data;
	}
public:
    bool HasEdge(int index0,int index1)
	{
		return relationMap[index0+index1*maxVertexSize]==1;
	}
	int GetNeighbours(int* neighbourIndices,int nodeIndex)
	{
		int count=0;
		for(int i=0;i<vertexCount;i++)
		{
			if(HasEdge(nodeIndex,i))
			{
				neighbourIndices[count]=i;
				count++;
			}
		}
		return count;
	}
	int GetEdgeCount()
	{
		return edgeCount;
	}
	int GetVertexCount()
	{
		return vertexCount;
	}
    void AddEdge(int index0,int index1)
	{
		if(relationMap[index0+index1*maxVertexSize]==0)
		{
			relationMap[index0+index1*maxVertexSize]=1;
			relationMap[index1+index0*maxVertexSize]=1;
			edgeCount++;
		}
	}
	void DeleteEdge(int index0,int index1)
	{
		if(relationMap[index0+index1*maxVertexSize]==1)
		{
			relationMap[index0+index1*maxVertexSize]=0;
			relationMap[index1+index0*maxVertexSize]=0;
			edgeCount--;
		}
	}
	void AddVertex(DataType value)
	{
		if(vertexCount==maxVertexSize)
			throw std::exception();
		Data[vertexCount]=value;
		this->vertexCount++;
	}
	void Travel(int startIndex,GraphTravelMethod method,void (*Process)(DataType value))
	{
		this->Action=Process;
		this->visitFlag=new bool[vertexCount];
		if(method==MDepthFirst)
		{
			DepthFirstTravel(startIndex);
		}
		if(method==MBreadthFirst)
		{
			BreathFirstTravel(startIndex);
		}
		delete[] visitFlag;
		this->visitFlag=0;
		this->Action=0;
	}
private:
	void DepthFirstTravel(int index)
	{
		if(!visitFlag[index])
		{
			Action(Data[index]);
			for(int i=0;i<vertexCount;i++)
			{
				if(HasEdge(index,i))
				{
					DepthFirstTravel(i);
				}
			}
		}
	}
	void BreathFirstTravel(int startIndex)
	{
		std::queue<int> queue;
		queue.push(startIndex);
		visitFlag[startIndex]=true;
		while(!queue.empty())
		{
			int index=queue.front();
			queue.pop();
			for(int i=0;i<vertexCount;i++)
			{
				if(HasEdge(index,i)&&!visitFlag[i])
				{
					queue.push(i);
					visitFlag[i]=true;
				}
			}
		}
	}

};
class UndirectedGraph_AdjacencyList:public UndirectedGraphBase
{
private:
	int maxVertexSize;
	int vertexCount;
	int edgeCount;
	std::vector<int>* adjacencyList;
public:
	UndirectedGraph_AdjacencyList(int maxVertexSize)
	{
		this->maxVertexSize=maxVertexSize;
		this->Data=new DataType[maxVertexSize];
		this->vertexCount=0;
		this->edgeCount=0;
		this->visitFlag=0;
		this->adjacencyList=new std::vector<int>[maxVertexSize];
	}
	~UndirectedGraph_AdjacencyList()
	{
		delete[] Data;
		delete[] adjacencyList;
	}
	bool HasEdge(int index0,int index1)
	{
		return std::find(adjacencyList[index0].begin(),adjacencyList[index0].end(),index1)!=adjacencyList[index0].end();
	}
	int GetNeighbours(int* neighbourIndices,int nodeIndex)
	{
		int count=0;
		for(size_t i=0;i<adjacencyList[nodeIndex].size();i++)
		{
			neighbourIndices[count]=adjacencyList[nodeIndex][i];
			count++;
		}
		return count;
	}
	int GetEdgeCount()
	{
		return edgeCount;
	}
	int GetVertexCount()
	{
		return vertexCount;
	}
	void AddEdge(int index0,int index1)
	{
		adjacencyList[index0].push_back(index1);
		adjacencyList[index1].push_back(index0);
		this->edgeCount++;
	}
	void DeleteEdge(int index0,int index1)
	{
		adjacencyList[index0].erase(remove(adjacencyList[index0].begin(),adjacencyList[index0].end(),index1),adjacencyList[index0].end());
		adjacencyList[index1].erase(remove(adjacencyList[index1].begin(),adjacencyList[index1].end(),index0),adjacencyList[index1].end());
		this->edgeCount--;
	}
	void AddVertex(DataType value)
	{
		if(vertexCount==maxVertexSize)
			throw std::exception();
		this->Data[vertexCount]=value;
		this->vertexCount++;
	}
	void Travel(int startIndex,GraphTravelMethod method,void (*Process)(DataType value))
	{
		this->Action=Process;
		this->visitFlag=new bool[vertexCount];
		if(method==MDepthFirst)
		{
			DepthFirstTravel(startIndex);
		}
		if(method==MBreadthFirst)
		{
			BreathFirstTravel(startIndex);
		}
		delete[] visitFlag;
		this->visitFlag=0;
		this->Action=0;
	}
private:
	void DepthFirstTravel(int index)
	{
		if(!visitFlag[index])
		{
			Action(Data[index]);
			for(size_t i=0;i<adjacencyList[index].size();i++)
			{
				DepthFirstTravel(i);
			}
		}
	}
	void BreathFirstTravel(int startIndex)
	{
		std::queue<int> queue;
		queue.push(startIndex);
		visitFlag[startIndex]=true;
		while(!queue.empty())
		{
			int index=queue.front();
			queue.pop();
			for(size_t i=0;i<adjacencyList[index].size();i++)
			{
				if(!visitFlag[i])
				{
					queue.push(i);
					visitFlag[i]=true;
				}
			}
		}
	}
};


#endif