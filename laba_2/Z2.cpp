#include<iostream>
#include<ctime>
using namespace std;

int main ()
{
    srand(time(0));
    int random;
    int rows;
    cout << "rows: ";
    cin >> rows;
    int **Arr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        random = rand() % 15 + 1;
        Arr[i] = new int[random];
        for (int j = 0; j < random; j++)
        {
            Arr[i][j] = 1;
            cout << Arr[i][j] << " ";
        }
        cout << endl; 
    }

    for(int i = 0; i < rows; i++)
            delete[] Arr[i];
    delete [] Arr;

    return 0;
}
