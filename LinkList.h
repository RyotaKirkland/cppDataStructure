#pragma once
#include <iostream>
using namespace std;

//单向链表类
template<class T>
class LinkList
{
public:
    LinkList();        //构造函数
    ~LinkList();       //析构函数
    LinkList<T>& Insert(int k, const T& x);
    bool IsEmpty() const;
    int GetLength() const;
    bool GetData(int k, T& x);
    bool ModifyData(int k, const T& x);
    int Find(const T& x);
    LinkList<T>& DeleteByIndex(int k, T& x);
    LinkList<T>& DeleteByKey(const T& x, T& y);
    void OutPut(ostream& out);
private:
    LinkNode<T>* head;       //指向链表的第一个头结点的指针
};

//构造函数（创建空的单向链表）
template<class T>
LinkList<T>::LinkList()
{
    head = new LinkNode<T>();        //创建头结点
}
//析构函数（清空单向链表）
template<class T>
LinkList<T>::~LinkList()
{
    T x;
    int length = GetLength();
    for (int i = length; i >= 1; i--)
        DeleteByIndex(i, x);        //释放所有结点
    delete head;                     //释放头结点
}
//实现插入新数据元素
template<class T>
LinkList<T>& LinkList<T>::Insert(int k, const T& x)
{
    LinkNode<T>* p = head;        //p指向头结点
    LinkNode<T>* newNode = new LinkNode<T>;        //创建待插入的新结点
    newNode->data = x;
    int length = GetLength();
    if (k < 1 || k > length + 1)
        cout << "元素下标越界，添加元素失败！";
    else
    {
        for (int i = 1; i < k; i++)
            p = p->next;
        newNode->next = p->next;
        p->next = newNode;
    }
    return *this;
}
//实现按位置删除
template<class T>
LinkList<T>& LinkList<T>::DeleteByIndex(int k, T& x)
{
    if (GetData(k, x))
    {
        LinkNode<T>* p = head;        //p指向头节点
        LinkNode<T>* q = NULL;        //q指向空地址
        for (int i = 1; i < k; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        delete q;
    }
    else
        cout << "元素下标越界，删除失败！";
    return *this;
}
//实现按关键字删除
template<class T>
LinkList<T>& LinkList<T>::DeleteByKey(const T& x, T& y)
{
    int index = Find(x);                //得到要删除元素的位置
    if (index != 0)
        return DeleteByIndex(index, y);
    else
    {
        cout << "找不到该元素，删除失败！";
        return *this;
    }
}
//判断是否为空表
template<class T>
bool LinkList<T>::IsEmpty() const
{
    return head->next == NULL;
}
//求当前表的长度
template<class T>
int LinkList<T>::GetLength() const
{
    int length = 0;
    LinkNode<T>* p = head->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}
//按位置取元素
template<class T>
bool LinkList<T>::GetData(int k, T& x)
{
    LinkNode<T>* p = head->next;
    int index = 1;
    if (k < 1 || k > GetLength())
        return false;
    while (p != NULL && index < k)
    {
        index++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        x = p->data;
        return true;
    }
}
//按位置修改元素
template<class T>
bool LinkList<T>::ModifyData(int k, const T& x)
{
    LinkNode<T>* p = head->next;
    int index = 1;
    if (k < 1 || k > GetLength())
        return false;
    while (p != NULL && index < k)
    {
        index++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        p->data = x;
        return true;
    }
}
//按关键字查找元素
template<class T>
int LinkList<T>::Find(const T& x)
{
    LinkNode<T>* p = head->next;
    int index = 1;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        index++;
    }
    if (p != NULL)
        return index;
    else
        return 0;
}
//实现单向链表的输出
template<class T>
void LinkList<T>::OutPut(ostream& out)
{
    LinkNode<T>* p = head->next;
    while (p != NULL)
    {
        out << p->data << endl;
        p->next;
    }
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, LinkList<T>& x)
{
    x.OutPut(out);
    return out;
}