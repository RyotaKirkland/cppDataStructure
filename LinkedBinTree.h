#pragma once
#include <iostream>
#include "LinkStack.h"        //链接栈类模板
#include "LinkQueue.h"        //链接队列类模板
using namespace std;

//结点类模板
template<class T>
class LinkedNode
{
    template<class T>
    friend class LinkedBinTree;
public:
    LinkedNode()                //构造函数
    {
        m_pLeftChild = m_pRightChild = NULL;
    }
    LinkedNode(const T& x)      //构造函数
    {
        m_pLeftChild = m_pRightChild = NULL;
        m_data = x;
    }
private:
    T m_data;
    LinkedNode<T>* m_pLeftChild, * m_pRightChild;
};
//二叉树二叉链表类模板
template<class T>
class LinkedBinTree
{
public:
    LinkedBinTree();                        //创建空二叉树
    ~LinkedBinTree();                       //删除二叉树
    bool IsEmpty();                         //判断二叉树是否为空
    LinkedNode<T>* CreateRoot(const T& x);  //以指定元素值创建根结点
    void Clear();                           //清空二叉树
    LinkedNode<T>* GetRoot();               //获取根结点
    LinkedNode<T>* InsertLeftChild(LinkedNode<T>* pNode, const T& x);
    //将一个结点作为指定结点的左孩子插入
    LinkedNode<T>* InsertRightChild(LinkedNode<T>* pNode, const T& x);
    //将一个结点作为指定结点的右孩子插入
    bool ModifyNodeValue(LinkedNode<T>* pNode, const T& x);
    //修改指定结点的元素值
    bool GetNodeValue(LinkedNode<T>* pNode, T& x);
    //获取指定结点的元素值
    LinkedNode<T>* GetLeftChild(LinkedNode<T>* pNode);
    //获取指定结点的左孩子结点
    LinkedNode<T>* GetRightChild(LinkedNode<T>* pNode);
    //获取指定结点的右孩子结点
    void PreOrderTraverse(LinkedNode<T>* pNode);        //按递归方式先序遍历
    void InOrderTraverse(LinkedNode<T>* pNode);         //按递归方式中序遍历
    void PostOrderTraverse(LinkedNode<T>* pNode);       //按递归方式后序遍历
    void PreOrderTraverse();                            //按非递归方式先序遍历
    void InOrderTraverse();                             //按非递归方式中序遍历
    void PostOrderTraverse();                           //按非递归方式后序遍历
    void LevelOrderTraverse();                          //按非递归方式逐层遍历
    LinkedNode<T>* GetParent(LinkedNode<T>* pNode);
    //按非递归方式获取指定结点的双亲结点
    void DeleteSubTree(LinkedNode<T>* pNode);
    //删除以指定结点为根的子树
    void DeleteSubTreeNode(LinkedNode<T>* pNode);
    //由DeleteSubTree函数调用按非递归方式删除以指定结点为根的子树
    LinkedNode<T>* SearchByKey(const T& x);
    //按非递归方式根据关键字查找结点
    void InsertBST(LinkedBinTree<T>& btree, T K);
    //二叉排序树插入新结点的实现，将元素K插入到二叉排序树btree中
    void CreateBST(T R[], int nSize, LinkedBinTree<T>& btree);
    //生成二叉排序树，根据传入数据集合R生成二叉排序树btree
    LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K);
    //以递归方式实现二叉排序树的查找
private:
    LinkedNode<T>* m_pRoot;      //指向根结点的指针
};

//实现创建空二叉树
template<class T>
LinkedBinTree<T>::LinkedBinTree()
{
    m_pRoot = NULL;        //将根结点的指针置为空
}
//实现以指定元素值创建根结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::CreateRoot(const T& x)
{
    if (m_pRoot != NULL)
        m_pRoot->m_data = x;        //若原先存在根结点，则直接将根结点的值置为x
    else                              //否则，创建一个新结点作为根结点
        m_pRoot = new LinkedNode<T>(x);
    return m_pRoot;
}
//判断二叉树是否为空
template<class T>
bool LinkedBinTree<T>::IsEmpty()
{
    if (m_pRoot == NULL)
        return true;
    return false;
}
//获取根结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRoot()
{
    return m_pRoot;
}
//将一个结点作为指定结点的左孩子插入
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
//将一个结点作为指定结点的右孩子插入
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
//修改指定结点的元素值
template<class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkedNode<T>* pNode, const T& x)
{
    if (pNode == NULL)
        return false;
    pNode->m_data = x;
    return true;
}
//获取指定结点的元素值
template<class T>
bool LinkedBinTree<T>::GetNodeValue(LinkedNode<T>* pNode, T& x)
{
    if (pNode == NULL)
        return false;
    x = pNode->m_data;
    return true;
}
//获取指定结点的左孩子结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetLeftChild(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return NULL;
    return pNode->m_pLeftChild;
}
//获取指定结点的右孩子结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRightChild(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return NULL;
    return pNode->m_pRightChild;
}
//按递归方式先序遍历
template<class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
}
//按非递归方式先序遍历
template<class T>
void LinkedBinTree<T>::PreOrderTraverse()
{
    LinkStack<LinkedNode<T>*> s;
    LinkedNode<T>* pNode = NULL;
    if (m_pRoot == NULL)
        return;
    s.Push(m_pRoot);                //将根结点入栈
    while (!s.IsEmpty())             //栈不为空时循环
    {
        s.Pop(pNode);                          //栈顶元素出栈并被访问
        cout << pNode->m_data << " ";
        if (pNode->m_pRightChild)             //若结点存在右子树，则将右子树根结点入栈
            s.Push(pNode->m_pRightChild);
        if (pNode->m_pLeftChild)              //若结点存在左子树，则将左子树根结点入栈
            s.Push(pNode->m_pLeftChild);
    }
}
//按递归方式中序遍历
template<class T>
void LinkedBinTree<T>::InOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    InOrderTraverse(pNode->m_pLeftChild);
    cout << pNode->m_data << " ";
    InOrderTraverse(pNode->m_pRightChild);
}
//按非递归方式中序遍历
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
//按递归方式后序遍历
template<class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkedNode<T>* pNode)
{
    if (pNode == NULL)
        return;
    PostOrderTraverse(pNode->m_pLefChild);
    PostOrderTraverse(pNode->m_pRightChild);
    cout << pNode->m_data << " ";
}
//按非递归方式后序遍历
template<class T>
void LinkedBinTree<T>::PostOrderTraverse()
{
    LinkStack<LinkedNode<T>*> s;;
    LinkedNode<T>* pNode;
    LinkedNode<T>* tmp = NULL;                         //保存节点上一次访问的状态
    while (pNode != NULL || !s.IsEmpty())
    {
        if (pNode != NULL)
        {
            s.Push(pNode);
            pNode = pNode->m_pLeftChild;             //左孩子结点
        }
        else
        {
            pNode = s.Top();                           //每次取栈顶元素
            if (pNode->m_pRightChild != NULL && pNode->m_pRightChild != tmp)
                //判断栈顶元素的右孩子是否为空，如果不为空，查看之前访问的结点是不是该栈顶元素的右孩子
                pNode = pNode->m_pRightchild;        //右孩子结点
            else
            {
                cout << pNode->m_data << " ";        //根结点
                s.Pop();
                tmp = pNode;                           //缓存上一次访问的节点
                pNode = NULL;                          //将指针置空
            }
        }
    }
}
//实现逐层遍历
template<class T>
void LinkedBinTree<T>::LevelOrderTraverse()
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pNode = NULL;
    if (m_pRoot == NULL)
        return;
    q.Insert(m_pRoot);                //将根结点入队
    while (!q.IsEmpty())              //当队列不为空时循环
    {
        q.Delete(pNode);              //将队头元素出队并访问
        cout << pNode->m_data << " ";
        if (pNode->m_pLefChild)
            q.Insert(pNode->m_pleftChild);        //若结点存在左子树，则将左子树根结点入队
        if (pNode->m_pRightChild)
            q.Insert(pNode->m_pRightChild);       //若结点存在右子树，则将右子树根结点入队
    }
}
//获取指定结点的双亲结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetParent(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pCurNode = NULL;
    if (pNode == m_pRoot)
        return NULL;                        //若指定结点pNode为根结点，则返回空
    if (m_pRoot == NULL)
        return NULL;                        //若二叉树是空树，则返回空
    q.Insert(m_pRoot);                      //将根结点入队
    while (!q.IsEmpty())                     //当队列不为空时循环
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
//按非递归方式删除以指定结点为根的子树
template<class T>
void LinkedBinTree<T>::DeleteSubTree(LinkedNode<T>* pNode)
{
    LinkedNode<T>* pParentNode = NULL;
    if (pNode == NULL)
        return;                             //若指定结点为空，则返回
    if (m_pRoot == pNode)
        m_pRoot = NULL;                     //若将整棵二叉树删除，则令根结点为空
    //否则，若指定结点存在双亲结点，则将双亲结点的左孩子或右孩子置空
    else if ((pParentNode = GetParent(pNode)) != NULL)
    {
        if (pParentNode->m_pLeftChild == pNode)
            pParentNode->m_pLeftChild = NULL;
        else
            pParentNode->m_pRightChild = NULL;
    }
    //否则，指定结点不是二叉树中的结点，直接返回else
    return;
    DeleteSubTreeNode(pNode);
    //调用DeleteSubTreeNode删除以pNode为根的子树
}
//由DeleteSubTree函数调用按非递归方式释放以指定结点为根的子树
template<class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pCurNode = NULL;
    if (pNode == NULL)
        return;
    //按非递归层次遍历的方式删除子树
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
//按非递归方式根据关键字查找结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::SearchByKey(const T& x)
{
    LinkQueue<LinkedNode<T>*> q;
    LinkedNode<T>* pMatchNode = NULL;
    if (m_pRoot == NULL)
        return NULL;
    //按非递归层次遍历的方式查找结点
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
//清空二叉树
template<class T>
void LinkedBinTree<T>::Clear()
{
    DeleteSubTree(m_pRoot);
}
//删除二叉树
template<class T>
LinkedBinTree<T>::~LinkedBinTree()
{
    Clear();        //清空二叉树中的结点
}
//二叉排序树插入新结点的实现，将元素K插入到二叉排序树btree中
template<class T>
void InsertBST(LinkedBinTree<T>& btree, T K)
{
    LinkedNode<T>* pNode = NULL, * pChild = NULL;
    T x;
    //若二叉排序树为空树，则将K作为根结点
    if (btree.IsEmpty())
    {
        btree.CreateRoot(K);
        return;
    }
    pNode = btree.GetRoot();
    while (pNode)
    {
        btree.GetNodeValue(pNode, x);
        if (K == x)                //若K已是二叉排序树中的结点
            return;
        if (K < x)                 //将K插入到该根结点的左子树中
        {
            //若根结点有左子树，则继续寻找新的位置
            if ((pChild = btree.GetLeftChild(pNode)) != NULL)
                pNode = pChild;
            else
                //否则，将新元素作为根结点的左孩子
            {
                btree.InsertLeftChild(pNode, K);
                return;
            }
        }
        else//将K插入到该根结点的右子树中
        {
            //若根结点有右子树，则继续寻找新的位置
            if ((pChild = btree.GetRightChild(pNode)) != NULL)
                pNode = pChild;
            else
                //否则，将新元素作为根结点的右孩子
            {
                btree.InsertRightChild(pNode, K);
                return;
            }
        }
    }
}
//生成二叉排序树，根据传入数据集合R生成二叉排序树btree
template<class T>
void CreateBST(T R[], int nSize, LinkedBinTree<T>& btree)
{
    int n;
    //将R中的元素逐一插入到二叉排序树btree中
    for (n = 1; n <= nSize; n++)
        InsertBST(btree, R[n - 1]);
}
//以递归方式实现二叉排序树的查找
template<class T>
LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K)
{
    LinkedBinTree<T> btree;
    T x;
    if (pRoot == NULL)            //若子树为空，则查找失败
        return NULL;
    btree.GetNodeValue(pRoot, x);
    if (K == x)                   //若K等于根结点的值，则查找成功
        return pRoot;
    else if (K < x)               //在左子树中继续进行二叉排序树的查找
        return SearchBST(btree.GetLeftChild(pRoot), K);
    else                         //否则在右子树中继续进行二叉排序树的查找
        return SearchBST(btree.GetRightChild(pRoot), K);
}