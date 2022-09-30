#include <iostream>

using namespace std;

class A
{
    protected:
        int x, y;
    public:
        A();
        void setXY(int x, int y);
        void getXY();
};

A::A():
    x(1),
    y(1)
{
    
}

void A::setXY(int X, int Y) {
    x = X;
    y = Y;
}

void A::getXY() {
    cout << x << " " << y << endl;
}

class B: public A
{
    int sum;
    public:
        B();
        void Sum();
        void getSum();
};

 B::B()
{
}

void B::Sum()
{
    sum = x + y;
}

void B::getSum() {
    cout << sum << endl;
}

int main () {
    B numB;
    numB.setXY(3, 10);
    numB.getXY();
    numB.Sum();
    numB.getSum();
    return 0;
}