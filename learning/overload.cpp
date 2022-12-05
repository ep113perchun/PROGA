#include <iostream>

using namespace std;

class MyClass
{
public:
    int* data;
    MyClass(int size)
    {
        this -> Size = size;
        this -> data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
        
        cout << "вызвался конструктор адресс:" << this << endl;
    };
    MyClass(const MyClass &other)
    {
        this -> Size = other.Size;
        this -> data = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }

        cout << "вызвался конструктор копирования адресс:" << this << endl;
    }
    MyClass & operator = (const MyClass &other)
    {
        cout << "оператор = перегружен" << endl;
        this->Size = other.Size;
        if(this->data != nullptr)
        {
            delete[] this->data;
        }
        this->data = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }
        return *this;
    }
    ~MyClass()
    {
        cout << "вызвался деструктор адресс:" << this << endl;
        delete[] data;
    };
private:
    int Size;
};

int main(){
    MyClass a(10);
    MyClass b(2);
    MyClass c(8);

    a = b = c;

    return 0;
}