#include <iostream>
#include <ctime>

using namespace std;

int** genRandMatrix(int size)
{
    int **Arr = new int*[size];
    for(int i = 0; i < size; i++)
    {
        Arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            Arr[i][j] = rand() % 9 + 1;
        }
    }
    return Arr;
}

void printMatrix(int** Arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }
}

void right_diagonals(int** Arr, int size)
{

}

void left_diagonals(int** Arr, int size)
{

}

void centr(int** Arr, int size)
{

}

void left_elements(int** Arr, int size)
{

}

int main ()
{
    srand(time(0));
    int size;
    int metod;
    cout << "size: ";
    cin >> size;

    int** Arr = genRandMatrix(size);
    printMatrix(Arr, size);

    cout << "1) right diagonals" << endl
         << "2) left diagonals"  << endl
         << "3) centr"           << endl
         << "4) left elements"   << endl
         << "enter: ";
    cin >> metod;
    if(metod == 1)
    {
        right_diagonals(Arr, size);
    }
    if(metod == 2)
    {
        left_diagonals(Arr, size);
    }
    if(metod == 3)
    {
        centr(Arr, size);
    }
    if(metod == 4);
    {
        left_elements(Arr, size);
    }

    for(int i = 0; i < size; i++)
            delete[] Arr[i];
    delete [] Arr;

    return 0;
}