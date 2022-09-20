#include<iostream>
#include<ctime>
using namespace std;

int** genRandMatrix(int size)
{
    int random;
    int **Arr = new int*[size];
    for(int i = 0; i < size; i++)
    {
        random = rand() % 15 + 1;
        Arr[i] = new int[random];
        for (int j = 1; j < random; j++)
        {
            Arr[i][0] = random;
            Arr[i][j] = rand() % 9 + 1;
        }
    }
    return Arr;
}

void printMatrix(int** Arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < Arr[i][0]; j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int size;
    cout << "size: ";
    cin >> size;

    int** Arr = genRandMatrix(size);
    printMatrix(Arr, size);

    for(int i = 0; i < size; i++)
            delete[] Arr[i];
    delete [] Arr;

    return 0;
}

// int main ()
// {
//     srand(time(0));
//     int random;
//     int rows;
//     cout << "rows: ";
//     cin >> rows;
//     int **Arr = new int*[rows];

//     for (int i = 0; i < rows; i++)
//     {
//         random = rand() % 15 + 1;
//         Arr[i] = new int[random];
//         for (int j = 0; j < random; j++)
//         {
//             Arr[i][j] = 1;
//             cout << Arr[i][j] << " ";
//         }
//         cout << endl; 
//     }

//     for(int i = 0; i < rows; i++)
//             delete[] Arr[i];
//     delete [] Arr;

//     return 0;
// }

