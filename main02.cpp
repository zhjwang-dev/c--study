//
// Created by zhjwang on 2021/4/14.

// 对引用计数做一个简易的封装，把引用计数作为一个新的类类使用

//但是依然存在两个问题：
//1. 如果对其中某一个类对象中的资源进行了修改，那么所有引用该资源的对象全部会被修改，这显然是错误的。
//2. 当前的计数器作用于Student类，在使用时候，需要强行加上引用计数类，这样复用性不好，使用不方便。

#include <iostream>
#include <string>
using namespace std;

struct RefValue
{
    RefValue(const char *pszName);
    ~RefValue();

    void AddRef();
    void Release();

    char *m_pszName;
    int m_nCount;
};

RefValue::RefValue(const char *pszName)
{
    m_pszName = new char[strlen(pszName) + 1];
    m_nCount = 1;
}

RefValue::~RefValue()
{
    if (m_pszName != nullptr)
    {
        delete m_pszName;
        m_pszName = nullptr;
    }
}

void RefValue::AddRef()
{
    m_nCount++;
}
void RefValue::Release()
{
    if (--m_nCount == 0)
    {
        delete this;
    }
}

class CStudent
{
public:
    CStudent(const char *pszName);
    CStudent(CStudent &obj);
    ~CStudent();
    CStudent &operator=(CStudent &obj);
    void release();
    void Show()
    {
        if (m_pValue->m_nCount > 0)
        {
            cout << hex << (int &)m_pValue->m_pszName << ":" << m_pValue->m_nCount << endl;
        }
    }

private:
    RefValue *m_pValue;
};

CStudent::CStudent(const char *pszName)
{
    m_pValue = new RefValue(pszName);
}

CStudent::CStudent(CStudent &obj)
{
    this->m_pValue = obj.m_pValue;
    this->m_pValue->AddRef();
}

CStudent::~CStudent()
{
    release();
}

CStudent &CStudent::operator=(CStudent &obj)
{
    if (obj.m_pValue == m_pValue)
    {
        return *this;
    }
    m_pValue->Release();
    m_pValue = obj.m_pValue;
    m_pValue->AddRef();
    return *this;
}

void CStudent::release()
{
    m_pValue->Release();
}

int main()
{
    CStudent stu1("zhang san");
    CStudent stu2("li si");
    CStudent stu3 = stu2; //首选拿到原有的引用计数赋值给自己，然后再把自己的引用计数加1,所以stu3是2

    //stu3 = stu1;

    stu1.Show(); //1
    stu2.Show(); //2
    stu3.Show(); //2
    return 0;
}