#include <iostream>
#include <ctime>

using namespace std;

int main ()
{
    srand(time(0));
    int size;
    cin >> size;
    int cols = size; //stolbci
    int rows = size; //stroki

    int **Arr = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        Arr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            Arr[i][j] = rand() % 9 + 1;
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }

    int Arr_D[4];

    for(int i = 0; i < size; i++)
            delete[] Arr[i];
    delete [] Arr;

    return 0;
}