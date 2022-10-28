#include <stdio.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int Sum(int input){
    int sum;
    if(input % 2 == 0) sum = 2;
    else sum = 0;

    for (int i = 3; i <= input; i += 2)
    {
        if (input % i == 0 && isPrime(i))
        {
            sum += i;
        }
    }
    return sum;
}



int main(void)
{
    int input;
    while (1)
    {
        cin >> input;
        if(input == 0) break;
        cout << "(" << Sum(input) << ")" << endl;
    }
    return 0;
}