#pragma once
#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
using namespace std;
const int INF = INT_MAX;				//定义整型最大值为无穷
const int MAX_VERTEX_NUM = 30;			//定义最大顶点数目为30
//图的邻接矩阵表示法类模板
template <class T>
class AdjGraph
{
private:
	T m_vertex[MAX_VERTEX_NUM];							//顶点集合
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//邻接矩阵
	int m_nVertexNum;									//实际顶点数目
	int m_nGraphType;									//图的类型（0为无向图，1为有向图）
public:
	AdjGraph(int nGraphType);			//创建图
	bool DFSTraverse(int nV, int);
	//以递归方式从下标为nV的顶点开始对图做深度优先遍历
	void DFSTraverse(int nV, bool bVisited[]);
	//由DFSTraverse调用以递归方式完成图的深度优先遍历
	bool DFSTraverse(int nV);
	//以非递归方式对图做深度优先遍历
	bool BFSTraverse(int nV);
	//从下标为nV的顶点开始对图做广度优先遍历
	int GetVertexNum();
	//获取顶点数目
	int GetFirstEdge(int nV);
	//获取与指定顶点nV关联的第一条边
	int GetNextEdge(int nV1, int nV2);
	//获取与指定边(nV1, nV2)或<nV1, nV2>有相同关联顶点的下一条边
	bool AddOneVertex(const T& vertex);				//添加一个顶点
	bool AddOneEdge(int nV1, int nV2, int nWeight);	//添加一条边
	bool GetVertexValue(int nV, T& vertex);			//获取一个顶点中存储的数据
	bool IsEdge(int nV1, int nV2);					//判断一条边是否存在
	bool SetEdgeWeight(int nV1, int nV2, int nWeight);
	//设置一条边的权
	bool GetEdgeWeight(int nV1, int nV2, int& nWeight);
	//获取一条边的权
};

//创建图
template <class T>
AdjGraph<T>::AdjGraph(int nGraphType)
{
	int ni, nj;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	//将任意两个结点之间的边的权设置为无穷大，初始时没有边
	for (ni = 0; ni < MAX_VERTEX_NUM; ni++) {
		for (nj = 0; nj < MAX_VERTEX_NUM; nj++) {
			m_nAdjMatrix[ni][nj] = INF;
		}
	}
}
//获取顶点数目
template <class T>
int AdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
//判断一条边是否存在
template <class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)
{
	return m_nAdjMatrix[nV1][nV2] != INF;
	//权重为有限值，则表明边存在
}
//获取与指定顶点nV相关联的第一条边
template <class T>
int AdjGraph<T>::GetFirstEdge(int nV)
{
	int nj;
	if (nV < 0 || nV >= m_nVertexNum)
		return -1;
	//找到第一条与nV相关联的边
	for (nj = 0; nj < m_nVertexNum; nj++)
		if (IsEdge(nV, nj))
			return nj;
	return -1;
}
//获取与指定边有相同关联顶点nV1的下一条边的nV1外的顶点
template <class T>
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nj;
	if (!IsEdge(nV1, nV2))
		return -1;
	//访问nV2后面的顶点，找到下一条与nV1关联的边
	for (nj = nV2 + 1; nj < m_nVertexNum; nj++)
		if (IsEdge(nV1, nj))
			return nj;
	return -1;
}
//添加一个顶点
template <class T>
bool AdjGraph<T>::AddOneVertex(const T& vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}
//获取一个顶点中存储的数据
template <class T>
bool AdjGraph<T>::GetVertexValue(int nV, T& Vertex)
{
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	Vertex = m_vertex[nV];
	return true;
}
//添加一条边
template <class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	//两个顶点必须存在，且两个顶点之间没有已存在的边
	if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum || IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType == 0)		//无向图
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}
//设置一条边的权
template <class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}
//获取一条边的权
template <class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int& nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}
//实现广度优先遍历
template <class T>
bool AdjGraph<T>::BFSTraverse(int nV)
{
	LinkQueue<int> queue;
	//队列存储顶点的下标值
	int nVisitVertex, nVertex, nBeginVertex = nV;
	//分别定义正在访问的顶点、边以及起始顶点（即nV）
	bool bVisited[MAX_VERTEX_NUM];
	//记录一个顶点是否已访问
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//各顶点均设置为未访问状态
	while (true)
	{
		queue.Insert(nBeginVertex);
		bVisited[nBeginVertex] = true;
		while (!queue.IsEmpty())
		{
			queue.Delete(nVisitVertex);				//队首元素出队，存储在nVisitVertex中
			GetVertexValue(nVisitVertex, vertex);	//读取当前访问顶点的值
			cout << vertex << ' ';					//输出当前访问顶点的值
			nVertex = GetFirstEdge(nVisitVertex);	//得到与当前访问顶点相关的第一条边
			while (nVertex != -1)					//如果成功读取了下一条边的顶点，则循环
			{
				if (bVisited[nVertex] == false)		//判断该顶点是否被读取过
				{
					queue.Insert(nVertex);			//如果未被访问过，将该顶点的下标入队
					bVisited[nVertex] = true;
				}
				nVertex = GetNextEdge(nVisitVertex, nVertex);	//读取当前访问顶点的下一条相关的边
			}
		}
		//如果还有未被访问的顶点，则从该顶点开始再做广度优先遍历
		int n = nBeginVertex + 1;
		for (; n < m_nVertexNum + nV; n++)
		//由于遍历不一定从第一个顶点开始，所以用m_nVertexNum + nV定义循环次数，使起始顶点前的各顶点也能被访问到
		{
			if (bVisited[n % m_nVertexNum] == false)
			//取余运算，为了判断到起始顶点前的各顶点，值为该顶点的下标
			{
				nBeginVertex = n % m_nVertexNum;
				break;
			}
		}
		if (n == m_nVertexNum + nV)
			break;		//如果所有顶点都已访问，退出循环
	}
	return true;
}
//以递归方式从下标为nV的顶点开始对图做深度优先遍历
template <class T>
bool AdjGraph<T>::DFSTraverse(int nV, int)
//第二个参数int是为了区分递归及非递归方式
{
	int nBeginVertex;
	bool bVisited[MAX_VERTEX_NUM];
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//各顶点均置为未访问状态
	//对于图中的每一个顶点，若为未访问状态，则从该顶点开始调用DFS函数对包含该顶点的连通子图进行深度优先遍历
	for (nBeginVertex = nV; nBeginVertex < m_nVertexNum + nV; nBeginVertex++)
	{
		if (bVisited[nBeginVertex % m_nVertexNum] = false)
			DFSTraverse(nBeginVertex, bVisited);
	}
	return true;
}
//由DFSTraverse调用以递归方式完成图的深度优先遍历
template <class T>
void AdjGraph<T>::DFSTraverse(int nV, bool bVisited[])
{
	T vertex;
	int nVertex;
	//先访问当前顶点，并将其状态设置为已访问
	GetVertexValue(nV, vertex);
	cout << vertex << ' ';
	bVisited[nV] = true;
	//逐个获取与当前顶点相邻接的顶点，若获取到的顶点未访问，则调用DFS函数对包含该顶点的连通子图进行深度优先遍历
	nVertex = GetFirstEdge(nV);
	while (nVertex != -1)
	{
		if (bVisited[nVertex] == false)
			DFSTraverse(nVertex, bVisited);
		nVertex = GetNextEdge(nV, nVertex);
	}
}
//以非递归方式对图做深度优先遍历
template <class T>
bool AdjGraph<T>::DFSTraverse(int nV)
{
	LinkStack<int> s;
	//栈存储顶点的下标值
	int nVisitVertex, nBeginVertex = nV;
	//分别定义正在访问的顶点以及起始顶点（即nV）
	bool bVisited[MAX_VERTEX_NUM];
	//记录一个顶点是否已访问
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//各顶点均设置为未访问状态
	s.Push(nBeginVertex);					//起点元素入栈
	bVisited[nBeginVertex] = true;
	while (true)
	{
		while (!s.IsEmpty())
		{
			s.Pop(nVisitVertex);					//栈顶元素出栈
			GetVertexValue(nVisitVertex, vertex);	//读取栈顶元素顶点的值
			cout << vertex << ' ';					//输出顶点的值
			for (int i = 0; i < m_nVertexNum; i++)
			//遍历邻接矩阵的第nVisitVertex行，如果第i列的权值不为INF，且下标为i的顶点未被访问，则将其入栈
			{
				if (bVisited[i] == 0 && m_nAdjMatrix[nVisitVertex][i] != INF)
				{
					s.Push(i);
					bVisited[i] = true;
				}
			}
		}
		//如果还有未被访问的顶点，则从该顶点开始再做深度优先遍历
		int n = nBeginVertex + 1;
		for (; n < m_nVertexNum + nV; n++)
			//由于遍历不一定从第一个顶点开始，所以用m_nVertexNum + nV定义循环次数，使起始顶点前的各顶点也能被访问到
		{
			if (bVisited[n % m_nVertexNum] == false)
				//取余运算，为了判断到起始顶点前的各顶点，值为该顶点的下标
			{
				nBeginVertex = n % m_nVertexNum;
				break;
			}
		}
		if (n == m_nVertexNum + nV)
			break;		//如果所有顶点都已访问，退出循环
	}
	return true;
}