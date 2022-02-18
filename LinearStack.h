#pragma once
#include <iostream>
using namespace std;

//顺序栈类模板
template <class T>
class LinearStack {
public:
    LinearStack(int LSMaxSize);      //构造函数，创建空栈
    ~LinearStack();                  //析构函数，删除栈
    bool IsEmpty();                  //栈空返回true，非空返回false
    bool IsFull();                   //栈满返回true，不满返回false
    int GetElementNumber();          //求栈中元素的个数
    bool Push(const T& x);           //在栈顶插入元素。成功返回true，失败返回false
    bool Top(T& x);                  //求栈顶元素值并放入x中。成功返回true，失败返回false
    bool Pop(T& x);                  //删除栈顶元素。成功返回true，失败返回false
    void OutPut(ostream& out) const; //将顺序栈放入输出流out中进行输出
private:
    int top;                         //用来表示栈顶
    int MaxSize;                     //栈中最大元素个数
    T* element;                      //一维动态数组
};

//实现构造函数
template<class T>
LinearStack<T>::LinearStack(int LSMaxSize)
{
    MaxSize = LSMaxSize;
    element = new T[LSMaxSize];
    top = -1;
}
//实现析构函数
template<class T>
LinearStack<T>::~LinearStack()
{
    delete[]element;
}
//判断栈是否为空
template<class T>
bool LinearStack<T>::IsEmpty()
{
    return top == -1;
}
//判断栈是否为满
template<class T>
bool LinearStack<T>::IsFull()
{
    return top + 1 == MaxSize;
}
//实现进栈
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
//求栈顶元素
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
//实现出栈
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
//实现顺序栈的输出，按栈底到栈顶的顺序输出
template<class T>
void LinearStack<T>::OutPut(ostream& out) const
{
    for (int i = 0; i <= top; i++) {
        out << element[i] << endl;
    }
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, const LinearStack<T>& x)
{
    x.OutPut(out);
    return out;
}