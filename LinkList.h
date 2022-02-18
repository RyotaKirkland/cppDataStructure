#pragma once
#include <iostream>
using namespace std;

//����������
template<class T>
class LinkList
{
public:
    LinkList();        //���캯��
    ~LinkList();       //��������
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
    LinkNode<T>* head;       //ָ������ĵ�һ��ͷ����ָ��
};

//���캯���������յĵ�������
template<class T>
LinkList<T>::LinkList()
{
    head = new LinkNode<T>();        //����ͷ���
}
//������������յ�������
template<class T>
LinkList<T>::~LinkList()
{
    T x;
    int length = GetLength();
    for (int i = length; i >= 1; i--)
        DeleteByIndex(i, x);        //�ͷ����н��
    delete head;                     //�ͷ�ͷ���
}
//ʵ�ֲ���������Ԫ��
template<class T>
LinkList<T>& LinkList<T>::Insert(int k, const T& x)
{
    LinkNode<T>* p = head;        //pָ��ͷ���
    LinkNode<T>* newNode = new LinkNode<T>;        //������������½��
    newNode->data = x;
    int length = GetLength();
    if (k < 1 || k > length + 1)
        cout << "Ԫ���±�Խ�磬���Ԫ��ʧ�ܣ�";
    else
    {
        for (int i = 1; i < k; i++)
            p = p->next;
        newNode->next = p->next;
        p->next = newNode;
    }
    return *this;
}
//ʵ�ְ�λ��ɾ��
template<class T>
LinkList<T>& LinkList<T>::DeleteByIndex(int k, T& x)
{
    if (GetData(k, x))
    {
        LinkNode<T>* p = head;        //pָ��ͷ�ڵ�
        LinkNode<T>* q = NULL;        //qָ��յ�ַ
        for (int i = 1; i < k; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        delete q;
    }
    else
        cout << "Ԫ���±�Խ�磬ɾ��ʧ�ܣ�";
    return *this;
}
//ʵ�ְ��ؼ���ɾ��
template<class T>
LinkList<T>& LinkList<T>::DeleteByKey(const T& x, T& y)
{
    int index = Find(x);                //�õ�Ҫɾ��Ԫ�ص�λ��
    if (index != 0)
        return DeleteByIndex(index, y);
    else
    {
        cout << "�Ҳ�����Ԫ�أ�ɾ��ʧ�ܣ�";
        return *this;
    }
}
//�ж��Ƿ�Ϊ�ձ�
template<class T>
bool LinkList<T>::IsEmpty() const
{
    return head->next == NULL;
}
//��ǰ��ĳ���
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
//��λ��ȡԪ��
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
//��λ���޸�Ԫ��
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
//���ؼ��ֲ���Ԫ��
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
//ʵ�ֵ�����������
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
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, LinkList<T>& x)
{
    x.OutPut(out);
    return out;
}