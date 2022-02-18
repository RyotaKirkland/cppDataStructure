#pragma once
#include <iostream>
using namespace std;

//顺序表类模板
template <class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T* element;                //指向顺序表的起始位置
public:
    LinearList(int LLMaxSize);
    ~LinearList();
    LinearList<T>& Insert(int k, const T& x);                //插入元素
    bool IsEmpty() const;                                     //判断表是否为空
    int GetLength() const;                                    //求当前表的长度
    bool GetData(int k, T& x);                               //按位置取元素
    bool ModifyData(int k, const T& x);                      //按位置修改元素
	int Find(const T& x);                                     //查找关键字为x的元素
    LinearList<T>& DeleteByIndex(int k, T& x);               //按位置删除元素
    LinearList<T>& DeleteByKey(const T& x, T& y);            //按关键字删除元素
    void Output(ostream& out) const;                         //输出顺序表
};

//实现构造函数
template<class T>
LinearList<T>::LinearList(int LLMaxSize)
{
    MaxSize = LLMaxSize;
    element = new T[LLMaxSize];
    length = 0;
}
//实现析构函数
template<class T>
LinearList<T>::~LinearList()
{
    delete[]element;
}
//在表中第i个位置插入新元素x
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
    if (k < 1 || k > length + 1)
        cout << "元素下标越界，添加元素失败！";
    else
        if (length == MaxSize)
            cout << "此表已满，无法添加新元素！";
        else
        {
            for (int i = length; i > k - 1; i--)
                element[i] = element[i - 1];        //移动元素
            element[k - 1] = x;                     //插入元素
            length++;                               //表长+1
        }
    return *this;
}
//判断是否为空表
template<class T>
bool LinearList<T>::IsEmpty() const
{
    return length == 0;
}
//求当前表的长度
template<class T>
int LinearList<T>::GetLength() const
{
    return length;
}
//按位置取元素
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
//按位置修改元素
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
//按关键字查找元素
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
//删除表中第i个位置的元素
template<class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k, T& x)
{
    if (GetData(k, x))
    {
        for (int i = k - 1; i < length; i++)
        {
            element[i] = element[i - 1];                //移动元素
        }
        length--;                                       //表长-1
    else
        cout << "元素下标越界，删除失败！";
    return *this;
    }
}
//按关键字删除元素
template<class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x, T& y)
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
//实现顺序表的输出
template<class T>
void LinearList<T>::Output(ostream& out) const
{
    for (i = 0; i < length; i++)
        out << element[i] << endl;
}
//重载插入运算符<<
template<class T>
ostream& operator <<(ostream& out, const LinearList<T>& x)
{
    x.Output(out);
    return out;
}