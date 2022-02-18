#pragma once
#include <iostream>
#include "LinkStack.h"        //����ջ��ģ��
#include "LinkQueue.h"        //���Ӷ�����ģ��
using namespace std;

//�����ģ��
template<class T>
class LinkedNode
{
    template<class T>
    friend class LinkedBinTree;
public:
    LinkedNode()                //���캯��
    {
        m_pLeftChild = m_pRightChild = NULL;
    }
    LinkedNode(const T& x)      //���캯��
    {
        m_pLeftChild = m_pRightChild = NULL;
        m_data = x;
    }
private:
    T m_data;
    LinkedNode<T>* m_pLeftChild, * m_pRightChild;
};
//����������������ģ��
template<class T>
class LinkedBinTree
{
public:
    LinkedBinTree();                        //�����ն�����
    ~LinkedBinTree();                       //ɾ��������
    bool IsEmpty();                         //�ж϶������Ƿ�Ϊ��
    LinkedNode<T>* CreateRoot(const T& x);  //��ָ��Ԫ��ֵ���������
    void Clear();                           //��ն�����
    LinkedNode<T>* GetRoot();               //��ȡ�����
    LinkedNode<T>* InsertLeftChild(LinkedNode<T>* pNode, const T& x);
    //��һ�������Ϊָ���������Ӳ���
    LinkedNode<T>* InsertRightChild(LinkedNode<T>* pNode, const T& x);
    //��һ�������Ϊָ�������Һ��Ӳ���
    bool ModifyNodeValue(LinkedNode<T>* pNode, const T& x);
    //�޸�ָ������Ԫ��ֵ
    bool GetNodeValue(LinkedNode<T>* pNode, T& x);
    //��ȡָ������Ԫ��ֵ
    LinkedNode<T>* GetLeftChild(LinkedNode<T>* pNode);
    //��ȡָ���������ӽ��
    LinkedNode<T>* GetRightChild(LinkedNode<T>* pNode);
    //��ȡָ�������Һ��ӽ��
    void PreOrderTraverse(LinkedNode<T>* pNode);        //���ݹ鷽ʽ�������
    void InOrderTraverse(LinkedNode<T>* pNode);         //���ݹ鷽ʽ�������
    void PostOrderTraverse(LinkedNode<T>* pNode);       //���ݹ鷽ʽ�������
    void PreOrderTraverse();                            //���ǵݹ鷽ʽ�������
    void InOrderTraverse();                             //���ǵݹ鷽ʽ�������
    void PostOrderTraverse();                           //���ǵݹ鷽ʽ�������
    void LevelOrderTraverse();                          //���ǵݹ鷽ʽ������
    LinkedNode<T>* GetParent(LinkedNode<T>* pNode);
    //���ǵݹ鷽ʽ��ȡָ������˫�׽��
    void DeleteSubTree(LinkedNode<T>* pNode);
    //ɾ����ָ�����Ϊ��������
    void DeleteSubTreeNode(LinkedNode<T>* pNode);
    //��DeleteSubTree�������ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
    LinkedNode<T>* SearchByKey(const T& x);
    //���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
    void InsertBST(LinkedBinTree<T>& btree, T K);
    //���������������½���ʵ�֣���Ԫ��K���뵽����������btree��
    void CreateBST(T R[], int nSize, LinkedBinTree<T>& btree);
    //���ɶ��������������ݴ������ݼ���R���ɶ���������btree
    LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K);
    //�Եݹ鷽ʽʵ�ֶ����������Ĳ���
private:
    LinkedNode<T>* m_pRoot;      //ָ�������ָ��
};

//ʵ�ִ����ն�����
template<class T>
LinkedBinTree<T>::LinkedBinTree()
{
    m_pRoot = NULL;        //��������ָ����Ϊ��
}
//ʵ����ָ��Ԫ��ֵ���������
template<class T>
LinkedNode<T>* LinkedBinTree<T>::CreateRoot(const T& x)
{
    if (m_pRoot != NULL)
        m_pRoot->m_data = x;        //��ԭ�ȴ��ڸ���㣬��ֱ�ӽ�������ֵ��Ϊx
    else                              //���򣬴���һ���½����Ϊ�����
        m_pRoot = new LinkedNode<T>(x);
    return m_pRoot;
}
//�ж϶������Ƿ�Ϊ��
template<class T>
bool LinkedBinTree<T>::IsEmpty()
{
    if (m_pRoot == NULL)
        return true;
    return false;
}
//��ȡ�����
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRoot()
{
    return m_pRoot;
}
//��һ�������Ϊָ���������Ӳ���
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkedNode<T>* pNode, const T& x)
{
    LinkedNode<T>* pNewNode;
    if (pNode == NULL)
        return NULL;
    pNewNode = new LinkedNode<T>(x);
    if (pNewNode == NULL)
        return NULL;
    pNode->m_pLeftChild = pNewNode;
    return pNewNode;
}
//��һ�������Ϊָ�������Һ��Ӳ���
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertRightChild(LinkedNode<T>* pNode, const T& x)
{
    LinkedNode<T>* pNewNode;
    if (pNode == NULL)
        return NULL;
    pNewNode = new LinkedNode<T>(x);
    if (pNewNode == NULL)
        return NULL;
    pNode->m_pRightChild = pNewNode;
    return pNewNode;
}
//�޸�ָ������Ԫ��ֵ
template<class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkedNode<T>* pNode, const T& x)
{
    if (pNode == NULL)
        return false;
    pNode->m_data = x;
    return true;
}
//��ȡָ������Ԫ��ֵ
template<class T>
bool LinkedBinTree<T>::GetNodeValue(LinkedNode<T>* pNode, T& x)
{
    if (pNode == NULL)
        return false;
    x = pNode->m_data;
    return true;
}
//��ȡָ���������ӽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetLeftChild(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return NULL;
    return pNode->m_pLeftChild;
}
//��ȡָ�������Һ��ӽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRightChild(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return NULL;
    return pNode->m_pRightChild;
}
//���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
}
//���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PreOrderTraverse()
{
    LinkStack<LinkedNode<T>*> s;
    LinkedNode<T>* pNode = NULL;
    if (m_pRoot == NULL)
        return;
    s.Push(m_pRoot);                //���������ջ
    while (!s.IsEmpty())             //ջ��Ϊ��ʱѭ��
    {
        s.Pop(pNode);                          //ջ��Ԫ�س�ջ��������
        cout << pNode->m_data << " ";
        if (pNode->m_pRightChild)             //�������������������������������ջ
            s.Push(pNode->m_pRightChild);
        if (pNode->m_pLeftChild)              //�������������������������������ջ
            s.Push(pNode->m_pLeftChild);
    }
}
//���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::InOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    InOrderTraverse(pNode->m_pLeftChild);
    cout << pNode->m_data << " ";
    InOrderTraverse(pNode->m_pRightChild);
}
//���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::InOrderTraverse()
{
    LinkStack<LinkedNode<T>*> s;
    LinkedNode<T>* pNode = m_pRoot;
    if (m_pRoot == NULL)
        return;
    while (pNode != NULL || !s.IsEmpty())
    {
        while (pNode != NULL)
        {
            s.Push(pNode);
            pNode = pNode->m_pLeftChild;
        }
        if (!s.IsEmpty())
        {
            s.Top(pNode);
            cout << pNode->m_data << " ";
            s.Pop(pNode);
            pNode = pNode->m_pRightChild;
        }
    }
}
//���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    PostOrderTraverse(pNode->m_pLefChild);
    PostOrderTraverse(pNode->m_pRightChild);
    cout << pNode->m_data << " ";
}
//���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PostOrderTraverse()
{
    LinkStack<LinkedNode<T>*> s;;
    LinkedNode<T>* pNode;
    LinkedNode<T>* tmp = NULL;                         //����ڵ���һ�η��ʵ�״̬
    while (pNode != NULL || !s.IsEmpty())
    {
        if (pNode != NULL)
        {
            s.Push(pNode);
            pNode = pNode->m_pLeftChild;             //���ӽ��
        }
        else
        {
            pNode = s.Top();                           //ÿ��ȡջ��Ԫ��
            if (pNode->m_pRightChild != NULL && pNode->m_pRightChild != tmp)
                //�ж�ջ��Ԫ�ص��Һ����Ƿ�Ϊ�գ������Ϊ�գ��鿴֮ǰ���ʵĽ���ǲ��Ǹ�ջ��Ԫ�ص��Һ���
                pNode = pNode->m_pRightchild;        //�Һ��ӽ��
            else
            {
                cout << pNode->m_data << " ";        //�����
                s.Pop();
                tmp = pNode;                           //������һ�η��ʵĽڵ�
                pNode = NULL;                          //��ָ���ÿ�
            }
        }
    }
}
//ʵ��������
template<class T>
void LinkedBinTree<T>::LevelOrderTraverse()
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pNode = NULL;
    if (m_pRoot == NULL)
        return;
    q.Insert(m_pRoot);                //����������
    while (!q.IsEmpty())              //�����в�Ϊ��ʱѭ��
    {
        q.Delete(pNode);              //����ͷԪ�س��Ӳ�����
        cout << pNode->m_data << " ";
        if (pNode->m_pLefChild)
            q.Insert(pNode->m_pleftChild);        //��������������������������������
        if (pNode->m_pRightChild)
            q.Insert(pNode->m_pRightChild);       //��������������������������������
    }
}
//��ȡָ������˫�׽��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetParent(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pCurNode = NULL;
    if (pNode == m_pRoot)
        return NULL;                        //��ָ�����pNodeΪ����㣬�򷵻ؿ�
    if (m_pRoot == NULL)
        return NULL;                        //���������ǿ������򷵻ؿ�
    q.Insert(m_pRoot);                      //����������
    while (!q.IsEmpty())                     //�����в�Ϊ��ʱѭ��
    {
        q.Delete(pCurNode);
        if (pCurNode->m_pLeftChild == pNode || pCurNode->m_pRightChild == pNode)
            return pCurNode;
        if (pCurNode->m_pLeftChild)
            q.Insert(pCurNode->m_pLeftChild);
        if (pCurNode->m_pRightChild)
            q.Insert(pCurNode->m_pRightChild);
    }
    return NULL;
}
//���ǵݹ鷽ʽɾ����ָ�����Ϊ��������
template<class T>
void LinkedBinTree<T>::DeleteSubTree(LinkedNode<T>* pNode)
{
    LinkedNode<T>* pParentNode = NULL;
    if (pNode == NULL)
        return;                             //��ָ�����Ϊ�գ��򷵻�
    if (m_pRoot == pNode)
        m_pRoot = NULL;                     //�������ö�����ɾ������������Ϊ��
    //������ָ��������˫�׽�㣬��˫�׽������ӻ��Һ����ÿ�
    else if ((pParentNode = GetParent(pNode)) != NULL)
    {
        if (pParentNode->m_pLeftChild == pNode)
            pParentNode->m_pLeftChild = NULL;
        else
            pParentNode->m_pRightChild = NULL;
    }
    //����ָ����㲻�Ƕ������еĽ�㣬ֱ�ӷ���else
    return;
    DeleteSubTreeNode(pNode);
    //����DeleteSubTreeNodeɾ����pNodeΪ��������
}
//��DeleteSubTree�������ð��ǵݹ鷽ʽ�ͷ���ָ�����Ϊ��������
template<class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pCurNode = NULL;
    if (pNode == NULL)
        return;
    //���ǵݹ��α����ķ�ʽɾ������
    q.Insert(pNode);
    while (!q.IsEmpty())
    {
        q.Delete(pCurNode);
        if (pCurNode->m_pLeftChild)
            q.Insert(pCurNode->m_pLeftChild);
        if (pCurNode->m_pRightChild)
            q.Insert(pCurNode->m_pRightChild);
        delete pCurNode;
    }
}
//���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::SearchByKey(const T& x)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pMatchNode = NULL;
    if (m_pRoot == NULL)
        return NULL;
    //���ǵݹ��α����ķ�ʽ���ҽ��
    q.Insert(m_pRoot);
    while (!q.IsEmpty())
    {
        q.Delete(pMatchNode);
        if (pMatchNode->m_data == x)
            return pMatchNode;
        if (pMatchNode->m_pLeftChild)
            q.Insert(pMatchNode->m_pLeftChild);
        if (pMatchNode->m_pRightChild)
            q.Insert(pMatchNode->m_pRightChild);
    }
    return NULL;
}
//��ն�����
template<class T>
void LinkedBinTree<T>::Clear()
{
    DeleteSubTree(m_pRoot);
}
//ɾ��������
template<class T>
LinkedBinTree<T>::~LinkedBinTree()
{
    Clear();        //��ն������еĽ��
}
//���������������½���ʵ�֣���Ԫ��K���뵽����������btree��
template<class T>
void InsertBST(LinkedBinTree<T>& btree, T K)
{
    LinkedNode<T>* pNode = NULL, * pChild = NULL;
    T x;
    //������������Ϊ��������K��Ϊ�����
    if (btree.IsEmpty())
    {
        btree.CreateRoot(K);
        return;
    }
    pNode = btree.GetRoot();
    while (pNode)
    {
        btree.GetNodeValue(pNode, x);
        if (K == x)                //��K���Ƕ����������еĽ��
            return;
        if (K < x)                 //��K���뵽�ø�������������
        {
            //����������������������Ѱ���µ�λ��
            if ((pChild = btree.GetLeftChild(pNode)) != NULL)
                pNode = pChild;
            else
                //���򣬽���Ԫ����Ϊ����������
            {
                btree.InsertLeftChild(pNode, K);
                return;
            }
        }
        else//��K���뵽�ø�������������
        {
            //����������������������Ѱ���µ�λ��
            if ((pChild = btree.GetRightChild(pNode)) != NULL)
                pNode = pChild;
            else
                //���򣬽���Ԫ����Ϊ�������Һ���
            {
                btree.InsertRightChild(pNode, K);
                return;
            }
        }
    }
}
//���ɶ��������������ݴ������ݼ���R���ɶ���������btree
template<class T>
void CreateBST(T R[], int nSize, LinkedBinTree<T>& btree)
{
    int n;
    //��R�е�Ԫ����һ���뵽����������btree��
    for (n = 1; n <= nSize; n++)
        InsertBST(btree, R[n - 1]);
}
//�Եݹ鷽ʽʵ�ֶ����������Ĳ���
template<class T>
LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K)
{
    LinkedBinTree<T> btree;
    T x;
    if (pRoot == NULL)            //������Ϊ�գ������ʧ��
        return NULL;
    btree.GetNodeValue(pRoot, x);
    if (K == x)                   //��K���ڸ�����ֵ������ҳɹ�
        return pRoot;
    else if (K < x)               //���������м������ж����������Ĳ���
        return SearchBST(btree.GetLeftChild(pRoot), K);
    else                         //�������������м������ж����������Ĳ���
        return SearchBST(btree.GetRightChild(pRoot), K);
}