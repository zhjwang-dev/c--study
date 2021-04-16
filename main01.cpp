//
// Created by zhjwang on 2021/4/9.
//

#include <iostream>

using namespace std;

class CStudent
{
private:
    char *name;
    int *count;

public:
    CStudent(const char *pName);
    CStudent(CStudent &obj);
    ~CStudent();
    CStudent &operator=(CStudent &obj);
    void show();
    void release();
};

CStudent::CStudent(const char *pName)
{
    this->name = new char[256];
    this->count = new int;
    strcpy(name, pName);
    *(this->count) = 1;
}

CStudent::CStudent(CStudent &obj)
{
    this->name = obj.name; //浅拷贝
    this->count = obj.count;
    (*(this->count))++;
}

CStudent::~CStudent()
{
    this->release();
}

CStudent &CStudent::operator=(CStudent &obj)
{

    if (obj.name == this->name)
    {
        return *this;
    }
    if (--(*count) == 0)
    { //=号操作是不影响指针的引用计数的个数的，所有要减1，把原有的指向减去
        delete name;
        name = nullptr;
        delete count;
    }
    this->name = obj.name; //浅拷贝
    this->count = obj.count;
    (*(this->count))++;

    return *this;
}

void CStudent::release()
{
    if (this->name != nullptr && --(*count) == 0)
    {
        delete this->name;
        this->name = nullptr;
        delete count;
        count = nullptr;
    }
}

void CStudent::show()
{
    cout << hex << (int &)(this->name) << ":" << name << endl;
    cout << "count:" << *(this->count) << endl;
}

int main01()
{
    CStudent obj("wang");
    obj.show(); //1
    CStudent obj1 = obj;
    obj1.show(); //2

    CStudent obj2 = obj;

    obj2.show();
    return 0;
}
