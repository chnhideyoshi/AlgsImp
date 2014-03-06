#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include <vector>
#include <queue>
#define WeightType int
#define MAX_Weight 2147483647
class UndirectedWeightedGraph
{
private:
	int vertexCount;
	WeightType** EdgesWeights;
public:
	UndirectedWeightedGraph(int vertexCount)
	{
		this->vertexCount=vertexCount;
		InitEdgeWeights();
	}
	~UndirectedWeightedGraph()
	{
		ReleaseEdges();
	}
public:
	void AddEdge(int i,int j,WeightType weight)
	{
		this->EdgesWeights[i][j]=weight;
		this->EdgesWeights[j][i]=weight;
	}
    bool HasEdge(int i,int j)
	{
		return EdgesWeights[i][j]!=MAX_Weight;
	}
	WeightType GetWeight(int i,int j)
	{
		return EdgesWeights[i][j];
	}
	int GetVertexCount()
	{
		return vertexCount;
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
private:
	void InitEdgeWeights()
	{
		this->EdgesWeights=new WeightType*[vertexCount];
		for(int i=0;i<vertexCount;i++)
		{
			EdgesWeights[i]=new WeightType[vertexCount];
			for(int j=0;j<vertexCount;j++)
			{
					EdgesWeights[i][j]=MAX_Weight;
			}
		}
	}
	void ReleaseEdges()
	{
		for(int i=0;i<vertexCount;i++)
		{
			delete[] EdgesWeights[i];
		}
		delete[] EdgesWeights;
	}
};
class Set
{
private:
	std::vector<bool> InSetFlags;
	std::vector<WeightType>* values;
public:
	Set(int count,std::vector<WeightType>* values)
	{
		this->InSetFlags.resize(count,false);
		this->values=values;
	}
	~Set()
	{

	}
	int GetTrueCount()
	{
		int count=0;
		for(size_t i=0;i<InSetFlags.size();i++)
		{
			if(InSetFlags[i])
				count++;
		}
		return count;
	}
	int ExtraceMinIndex()
	{
		int index=-1;
		WeightType min=MAX_Weight;
		for(size_t i=0;i<InSetFlags.size();i++)
		{
			if(!InSetFlags[i])
			{
				if((*values)[i]<min)
				{
					min=(*values)[i];
					index=i;
				}
			}
		}
		return index;
	}
	void AddInSet(int index)
	{
		if(!InSetFlags[index])
			InSetFlags[index]=true;
		else
			throw std::exception();
	}
	bool InSet(int index)
	{
		return InSetFlags[index];
	}
};
class DijkstraProcessor 
{
private:
	int startIndex;
	UndirectedWeightedGraph* graph;
	std::vector<WeightType> DistenceTo;
	std::vector<int> ParentTo;
	int* tempArray;
	Set* ShortestPathFoundSet;
public:
	DijkstraProcessor(UndirectedWeightedGraph* graph,int startIndex)
	{
		this->startIndex=startIndex;
		this->graph=graph;
		this->DistenceTo.resize(graph->GetVertexCount(),MAX_Weight);
		this->ParentTo.resize(graph->GetVertexCount(),-1);
		this->ShortestPathFoundSet=new Set(graph->GetVertexCount(),&DistenceTo);
	}
	~DijkstraProcessor()
	{
		
	}
	void ExecuteDijkstra()
	{
		tempArray=new int[graph->GetVertexCount()];
		Initialize();
		while(ShortestPathFoundSet->GetTrueCount()!=graph->GetVertexCount())
		{
			int minIndex=ShortestPathFoundSet->ExtraceMinIndex();//////////////////////////////////////////////////////////////////////////Stra
			ShortestPathFoundSet->AddInSet(minIndex);
			int neighbourCounts=graph->GetNeighbours(tempArray,minIndex);
			for(int i=0;i<neighbourCounts;i++)
			{
				int neighbour=tempArray[i];
				if(!ShortestPathFoundSet->InSet(neighbour))
				{
					WeightType pathPassminIndexToN=DistenceTo[minIndex]+graph->GetWeight(minIndex,neighbour);
					WeightType pathToN=DistenceTo[neighbour];
					if(pathPassminIndexToN<pathToN)
					{
						DistenceTo[neighbour]=pathPassminIndexToN;
						ParentTo[neighbour]=minIndex;
					}
				}
				
			}
		}
		delete[] tempArray;
	}
	void GetShortestPathTo(int endIndex,std::vector<int>& path)
	{
		path.clear();
		int current=endIndex;
		path.push_back(endIndex);
		while(current!=startIndex)
		{
			path.push_back(ParentTo[current]);
			current=ParentTo[current];
		}
		std::reverse(path.begin(),path.end());
	}
	WeightType GetShortestDistenceTo(int endIndex)
	{
		return DistenceTo[endIndex];
	}
private:
	void Initialize()
	{
		int neighbourCounts=graph->GetNeighbours(tempArray,startIndex);
		for(int i=0;i<neighbourCounts;i++)
		{
			int neighbour=tempArray[i];
			ParentTo[neighbour]=startIndex;
			DistenceTo[neighbour]=graph->GetWeight(startIndex,neighbour);
		}
		ShortestPathFoundSet->AddInSet(startIndex);
		DistenceTo[startIndex]=0;
	}
public:
	static void PrintPath(std::vector<int>& path)
	{
		for(size_t i=0;i<path.size();i++)
		{
			printf("%d,",path[i]);
		}
		printf("\n");
	}
};
#endif