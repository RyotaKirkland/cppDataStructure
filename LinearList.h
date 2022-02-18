#pragma once
#include <iostream>
using namespace std;

//˳�����ģ��
template <class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T* element;                //ָ��˳������ʼλ��
public:
    LinearList(int LLMaxSize);
    ~LinearList();
    LinearList<T>& Insert(int k, const T& x);                //����Ԫ��
    bool IsEmpty() const;                                     //�жϱ��Ƿ�Ϊ��
    int GetLength() const;                                    //��ǰ��ĳ���
    bool GetData(int k, T& x);                               //��λ��ȡԪ��
    bool ModifyData(int k, const T& x);                      //��λ���޸�Ԫ��
	int Find(const T& x);                                     //���ҹؼ���Ϊx��Ԫ��
    LinearList<T>& DeleteByIndex(int k, T& x);               //��λ��ɾ��Ԫ��
    LinearList<T>& DeleteByKey(const T& x, T& y);            //���ؼ���ɾ��Ԫ��
    void Output(ostream& out) const;                         //���˳���
};

//ʵ�ֹ��캯��
template<class T>
LinearList<T>::LinearList(int LLMaxSize)
{
    MaxSize = LLMaxSize;
    element = new T[LLMaxSize];
    length = 0;
}
//ʵ����������
template<class T>
LinearList<T>::~LinearList()
{
    delete[]element;
}
//�ڱ��е�i��λ�ò�����Ԫ��x
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
    if (k < 1 || k > length + 1)
        cout << "Ԫ���±�Խ�磬���Ԫ��ʧ�ܣ�";
    else
        if (length == MaxSize)
            cout << "�˱��������޷������Ԫ�أ�";
        else
        {
            for (int i = length; i > k - 1; i--)
                element[i] = element[i - 1];        //�ƶ�Ԫ��
            element[k - 1] = x;                     //����Ԫ��
            length++;                               //��+1
        }
    return *this;
}
//�ж��Ƿ�Ϊ�ձ�
template<class T>
bool LinearList<T>::IsEmpty() const
{
    return length == 0;
}
//��ǰ��ĳ���
template<class T>
int LinearList<T>::GetLength() const
{
    return length;
}
//��λ��ȡԪ��
template<class T>
bool LinearList<T>::GetData(int k, T& x)
{
    if (k < 1 || k > length)
        return false;
    else
    {
        x = element[k - 1];
        return true;
    }
}
//��λ���޸�Ԫ��
template<class T>
bool LinearList<T>::ModifyData(int k, const T& x)
{
    if (k < 1 || k > length)
        return false;
    else
    {
        element[k - 1] = x;
        return true;
    }
}
//���ؼ��ֲ���Ԫ��
template<class T>
int LinearList<T>::Find(const T& x)
{
    for (int i = 0; i < length; i++)
    {
        if (element[i] == x)
            return i + 1;
    }
    return 0;
}
//ɾ�����е�i��λ�õ�Ԫ��
template<class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k, T& x)
{
    if (GetData(k, x))
    {
        for (int i = k - 1; i < length; i++)
        {
            element[i] = element[i - 1];                //�ƶ�Ԫ��
        }
        length--;                                       //��-1
    else
        cout << "Ԫ���±�Խ�磬ɾ��ʧ�ܣ�";
    return *this;
    }
}
//���ؼ���ɾ��Ԫ��
template<class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x, T& y)
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
//ʵ��˳�������
template<class T>
void LinearList<T>::Output(ostream& out) const
{
    for (i = 0; i < length; i++)
        out << element[i] << endl;
}
//���ز��������<<
template<class T>
ostream& operator <<(ostream& out, const LinearList<T>& x)
{
    x.Output(out);
    return out;
}