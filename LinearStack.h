#pragma once
#include <iostream>
using namespace std;

//˳��ջ��ģ��
template <class T>
class LinearStack {
public:
    LinearStack(int LSMaxSize);      //���캯����������ջ
    ~LinearStack();                  //����������ɾ��ջ
    bool IsEmpty();                  //ջ�շ���true���ǿշ���false
    bool IsFull();                   //ջ������true����������false
    int GetElementNumber();          //��ջ��Ԫ�صĸ���
    bool Push(const T& x);           //��ջ������Ԫ�ء��ɹ�����true��ʧ�ܷ���false
    bool Top(T& x);                  //��ջ��Ԫ��ֵ������x�С��ɹ�����true��ʧ�ܷ���false
    bool Pop(T& x);                  //ɾ��ջ��Ԫ�ء��ɹ�����true��ʧ�ܷ���false
    void OutPut(ostream& out) const; //��˳��ջ���������out�н������
private:
    int top;                         //������ʾջ��
    int MaxSize;                     //ջ�����Ԫ�ظ���
    T* element;                      //һά��̬����
};

//ʵ�ֹ��캯��
template<class T>
LinearStack<T>::LinearStack(int LSMaxSize)
{
    MaxSize = LSMaxSize;
    element = new T[LSMaxSize];
    top = -1;
}
//ʵ����������
template<class T>
LinearStack<T>::~LinearStack()
{
    delete[]element;
}
//�ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearStack<T>::IsEmpty()
{
    return top == -1;
}
//�ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearStack<T>::IsFull()
{
    return top + 1 == MaxSize;
}
//ʵ�ֽ�ջ
template<class T>
bool LinearStack<T>::Push(const T& x)
{
    if (IsFull())
        return false;
    else
    {
        top++;
        element[top] = x;
        return true;
    }
}
//��ջ��Ԫ��
template<class T>
bool LinearStack<T>::Top(T& x)
{
    if (IsEmpty())
        return false;
    else
    {
        x = element[top];
        return true;
    }
}
//ʵ�ֳ�ջ
template<class T>
bool LinearStack<T>::Pop(T& x)
{
    if (IsEmpty())
        return false;
    else
    {
        x = element[top];
        top--;
        return true;
    }
}
//ʵ��˳��ջ���������ջ�׵�ջ����˳�����
template<class T>
void LinearStack<T>::OutPut(ostream& out) const
{
    for (int i = 0; i <= top; i++) {
        out << element[i] << endl;
    }
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, const LinearStack<T>& x)
{
    x.OutPut(out);
    return out;
}