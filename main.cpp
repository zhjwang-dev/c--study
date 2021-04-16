#include <iostream>

using namespace std;

class CStudent
{
private:
    char *name;

public:
    CStudent(const char *pName);
    CStudent(CStudent &obj);
    CStudent &operator=(CStudent &obj);
    void show();
    void release();
};

CStudent::CStudent(const char *pName)
{
    this->name = new char[256];
    strcpy(name, pName);
}

CStudent::CStudent(CStudent &obj)
{
    this->name = obj.name; //浅拷贝
}

CStudent &CStudent::operator=(CStudent &obj)
{
    this->name = obj.name; //浅拷贝
    return *this;
}

void CStudent::release()
{
    if (this->name != nullptr)
    {
        delete this->name;
        this->name = NULL;
    }
}

void CStudent::show()
{
    cout << hex << (int &)(this->name) << ":" << name << endl;
}

int main00()
{
    CStudent obj("wang");
    obj.show();          //1a405aa0
    CStudent obj1 = obj; //拷贝构造
    obj1.show();         //1a405aa0

    CStudent obj2 = obj1;
    obj2 = obj1; //重载=操作符
    obj2.show(); //1a405aa0

    //这种方式的问题就是一个资源释放了，其他的也跟着释放了
    //可以通过增加一个变量，去记录使用次数，来解决这个问题
    obj.release();
    obj1.show(); //name为空
    obj2.show(); //name为空

    return 0;
}
