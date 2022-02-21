#pragma once
#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
using namespace std;
const int INF = INT_MAX;				//�����������ֵΪ����
const int MAX_VERTEX_NUM = 30;			//������󶥵���ĿΪ30
//ͼ���ڽӾ����ʾ����ģ��
template <class T>
class AdjGraph
{
private:
	T m_vertex[MAX_VERTEX_NUM];							//���㼯��
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ڽӾ���
	int m_nVertexNum;									//ʵ�ʶ�����Ŀ
	int m_nGraphType;									//ͼ�����ͣ�0Ϊ����ͼ��1Ϊ����ͼ��
public:
	AdjGraph(int nGraphType);			//����ͼ
	bool DFSTraverse(int nV, int);
	//�Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	void DFSTraverse(int nV, bool bVisited[]);
	//��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
	bool DFSTraverse(int nV);
	//�Էǵݹ鷽ʽ��ͼ��������ȱ���
	bool BFSTraverse(int nV);
	//���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	int GetVertexNum();
	//��ȡ������Ŀ
	int GetFirstEdge(int nV);
	//��ȡ��ָ������nV�����ĵ�һ����
	int GetNextEdge(int nV1, int nV2);
	//��ȡ��ָ����(nV1, nV2)��<nV1, nV2>����ͬ�����������һ����
	bool AddOneVertex(const T& vertex);				//���һ������
	bool AddOneEdge(int nV1, int nV2, int nWeight);	//���һ����
	bool GetVertexValue(int nV, T& vertex);			//��ȡһ�������д洢������
	bool IsEdge(int nV1, int nV2);					//�ж�һ�����Ƿ����
	bool SetEdgeWeight(int nV1, int nV2, int nWeight);
	//����һ���ߵ�Ȩ
	bool GetEdgeWeight(int nV1, int nV2, int& nWeight);
	//��ȡһ���ߵ�Ȩ
};

//����ͼ
template <class T>
AdjGraph<T>::AdjGraph(int nGraphType)
{
	int ni, nj;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	//�������������֮��ıߵ�Ȩ����Ϊ����󣬳�ʼʱû�б�
	for (ni = 0; ni < MAX_VERTEX_NUM; ni++) {
		for (nj = 0; nj < MAX_VERTEX_NUM; nj++) {
			m_nAdjMatrix[ni][nj] = INF;
		}
	}
}
//��ȡ������Ŀ
template <class T>
int AdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
//�ж�һ�����Ƿ����
template <class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)
{
	return m_nAdjMatrix[nV1][nV2] != INF;
	//Ȩ��Ϊ����ֵ��������ߴ���
}
//��ȡ��ָ������nV������ĵ�һ����
template <class T>
int AdjGraph<T>::GetFirstEdge(int nV)
{
	int nj;
	if (nV < 0 || nV >= m_nVertexNum)
		return -1;
	//�ҵ���һ����nV������ı�
	for (nj = 0; nj < m_nVertexNum; nj++)
		if (IsEdge(nV, nj))
			return nj;
	return -1;
}
//��ȡ��ָ��������ͬ��������nV1����һ���ߵ�nV1��Ķ���
template <class T>
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nj;
	if (!IsEdge(nV1, nV2))
		return -1;
	//����nV2����Ķ��㣬�ҵ���һ����nV1�����ı�
	for (nj = nV2 + 1; nj < m_nVertexNum; nj++)
		if (IsEdge(nV1, nj))
			return nj;
	return -1;
}
//���һ������
template <class T>
bool AdjGraph<T>::AddOneVertex(const T& vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}
//��ȡһ�������д洢������
template <class T>
bool AdjGraph<T>::GetVertexValue(int nV, T& Vertex)
{
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	Vertex = m_vertex[nV];
	return true;
}
//���һ����
template <class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	//�������������ڣ�����������֮��û���Ѵ��ڵı�
	if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum || IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType == 0)		//����ͼ
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}
//����һ���ߵ�Ȩ
template <class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}
//��ȡһ���ߵ�Ȩ
template <class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int& nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}
//ʵ�ֹ�����ȱ���
template <class T>
bool AdjGraph<T>::BFSTraverse(int nV)
{
	LinkQueue<int> queue;
	//���д洢������±�ֵ
	int nVisitVertex, nVertex, nBeginVertex = nV;
	//�ֱ������ڷ��ʵĶ��㡢���Լ���ʼ���㣨��nV��
	bool bVisited[MAX_VERTEX_NUM];
	//��¼һ�������Ƿ��ѷ���
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//�����������Ϊδ����״̬
	while (true)
	{
		queue.Insert(nBeginVertex);
		bVisited[nBeginVertex] = true;
		while (!queue.IsEmpty())
		{
			queue.Delete(nVisitVertex);				//����Ԫ�س��ӣ��洢��nVisitVertex��
			GetVertexValue(nVisitVertex, vertex);	//��ȡ��ǰ���ʶ����ֵ
			cout << vertex << ' ';					//�����ǰ���ʶ����ֵ
			nVertex = GetFirstEdge(nVisitVertex);	//�õ��뵱ǰ���ʶ�����صĵ�һ����
			while (nVertex != -1)					//����ɹ���ȡ����һ���ߵĶ��㣬��ѭ��
			{
				if (bVisited[nVertex] == false)		//�жϸö����Ƿ񱻶�ȡ��
				{
					queue.Insert(nVertex);			//���δ�����ʹ������ö�����±����
					bVisited[nVertex] = true;
				}
				nVertex = GetNextEdge(nVisitVertex, nVertex);	//��ȡ��ǰ���ʶ������һ����صı�
			}
		}
		//�������δ�����ʵĶ��㣬��Ӹö��㿪ʼ����������ȱ���
		int n = nBeginVertex + 1;
		for (; n < m_nVertexNum + nV; n++)
		//���ڱ�����һ���ӵ�һ�����㿪ʼ��������m_nVertexNum + nV����ѭ��������ʹ��ʼ����ǰ�ĸ�����Ҳ�ܱ����ʵ�
		{
			if (bVisited[n % m_nVertexNum] == false)
			//ȡ�����㣬Ϊ���жϵ���ʼ����ǰ�ĸ����㣬ֵΪ�ö�����±�
			{
				nBeginVertex = n % m_nVertexNum;
				break;
			}
		}
		if (n == m_nVertexNum + nV)
			break;		//������ж��㶼�ѷ��ʣ��˳�ѭ��
	}
	return true;
}
//�Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
template <class T>
bool AdjGraph<T>::DFSTraverse(int nV, int)
//�ڶ�������int��Ϊ�����ֵݹ鼰�ǵݹ鷽ʽ
{
	int nBeginVertex;
	bool bVisited[MAX_VERTEX_NUM];
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//���������Ϊδ����״̬
	//����ͼ�е�ÿһ�����㣬��Ϊδ����״̬����Ӹö��㿪ʼ����DFS�����԰����ö������ͨ��ͼ����������ȱ���
	for (nBeginVertex = nV; nBeginVertex < m_nVertexNum + nV; nBeginVertex++)
	{
		if (bVisited[nBeginVertex % m_nVertexNum] = false)
			DFSTraverse(nBeginVertex, bVisited);
	}
	return true;
}
//��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
template <class T>
void AdjGraph<T>::DFSTraverse(int nV, bool bVisited[])
{
	T vertex;
	int nVertex;
	//�ȷ��ʵ�ǰ���㣬������״̬����Ϊ�ѷ���
	GetVertexValue(nV, vertex);
	cout << vertex << ' ';
	bVisited[nV] = true;
	//�����ȡ�뵱ǰ�������ڽӵĶ��㣬����ȡ���Ķ���δ���ʣ������DFS�����԰����ö������ͨ��ͼ����������ȱ���
	nVertex = GetFirstEdge(nV);
	while (nVertex != -1)
	{
		if (bVisited[nVertex] == false)
			DFSTraverse(nVertex, bVisited);
		nVertex = GetNextEdge(nV, nVertex);
	}
}
//�Էǵݹ鷽ʽ��ͼ��������ȱ���
template <class T>
bool AdjGraph<T>::DFSTraverse(int nV)
{
	LinkStack<int> s;
	//ջ�洢������±�ֵ
	int nVisitVertex, nBeginVertex = nV;
	//�ֱ������ڷ��ʵĶ����Լ���ʼ���㣨��nV��
	bool bVisited[MAX_VERTEX_NUM];
	//��¼һ�������Ƿ��ѷ���
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//�����������Ϊδ����״̬
	s.Push(nBeginVertex);					//���Ԫ����ջ
	bVisited[nBeginVertex] = true;
	while (true)
	{
		while (!s.IsEmpty())
		{
			s.Pop(nVisitVertex);					//ջ��Ԫ�س�ջ
			GetVertexValue(nVisitVertex, vertex);	//��ȡջ��Ԫ�ض����ֵ
			cout << vertex << ' ';					//��������ֵ
			for (int i = 0; i < m_nVertexNum; i++)
			//�����ڽӾ���ĵ�nVisitVertex�У������i�е�Ȩֵ��ΪINF�����±�Ϊi�Ķ���δ�����ʣ�������ջ
			{
				if (bVisited[i] == 0 && m_nAdjMatrix[nVisitVertex][i] != INF)
				{
					s.Push(i);
					bVisited[i] = true;
				}
			}
		}
		//�������δ�����ʵĶ��㣬��Ӹö��㿪ʼ����������ȱ���
		int n = nBeginVertex + 1;
		for (; n < m_nVertexNum + nV; n++)
			//���ڱ�����һ���ӵ�һ�����㿪ʼ��������m_nVertexNum + nV����ѭ��������ʹ��ʼ����ǰ�ĸ�����Ҳ�ܱ����ʵ�
		{
			if (bVisited[n % m_nVertexNum] == false)
				//ȡ�����㣬Ϊ���жϵ���ʼ����ǰ�ĸ����㣬ֵΪ�ö�����±�
			{
				nBeginVertex = n % m_nVertexNum;
				break;
			}
		}
		if (n == m_nVertexNum + nV)
			break;		//������ж��㶼�ѷ��ʣ��˳�ѭ��
	}
	return true;
}