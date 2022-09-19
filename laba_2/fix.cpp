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

void printD(int D[], int size)
{
    for (int i = 0; i < size * size; i++)
    {
        cout << D[i] << " ";
    }
    cout << endl;
}

void right_diagonals(int** Arr, int D[], int size)
{
    int flag = 0;

    for (int i = 0, j = size-1; i < size && j >= 0; i++, j--)
    {
        for (int i_1 = i, i_2 = size-1; i_1 >= 0 && i_2 >= j; i_1--, i_2--)
        {
            D[flag] = Arr[i_1][i_2];
            flag += 1;
        }   
    }
    for (int i = 1, j = size-2; i < size && j >= 0; i++, j--)
    {
        for (int i_1 = size-1, i_2 = j; i_1 >= i && i_2 >= 0; i_1--, i_2--)
        {
            D[flag] = Arr[i_1][i_2];
            flag += 1;
        }
    }
    printD(D, size);
}

void left_diagonals(int** Arr, int D[], int size)
{
    int flag = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int i_1 = i, i_2 = 0; i_1 >= 0 && i_2 < i+1; i_1--, i_2++)
        {
            D[flag] = Arr[i_1][i_2];
            flag += 1;
        }     
    }
    for (int i = 1; i < size; i++)
    {
        for (int i_1 = size-1, i_2 = i; i_1 >= i && i_2 < size; i_1--, i_2++)
        {
            D[flag] = Arr[i_1][i_2];
            flag += 1;
        }
    }
    printD(D, size);
}

void metod (int pol, int L, int P, int st ,int D[], int** Arr, int &N)
{
    //cout << "sdlkflsfjl";
    if(pol == 0)
    {
        if(L > P){   //l
            for (int i = L; i >= P; i--)
            {
                D[N] = Arr[st][i];
                N += 1;
            }
        }
        if(L < P){   //r
            for (int i = L; i <= P; i++)
            {
                D[N] = Arr[st][i];
                N += 1;
            }
        }
        if(L == P){
            D[N] = Arr[st][L];
            N += 1;
        }
    }
    if(pol == 1)
    {
        if(L > P){
            for (int i = L; i >= P; i--)
            {
                D[N] = Arr[i][st];
                N += 1;
            }
        }
        if(L < P){
            for (int i = L; i <= P; i++)
            {
                D[N] = Arr[i][st];
                N += 1;
            }
        }
        if(L == P){
            D[N] = Arr[L][st];
            N += 1;
        }
        
    }
}

void left_elements(int** Arr, int D[], int size)
{
    int N = 0;
    int lr = 0, pr = size - 1, r = 0;
    int ld = 1, pd = size - 1, d = size - 1;
    int ll = size - 2, pl = 0, l = size - 1;
    int lu = size - 2, pu = 1, u = 0;
    cout << endl;
    while(1)
    {
        metod(0, lr, pr, r, D, Arr, N); if(lr == pr){break;}//right
        metod(1, ld, pd, d, D, Arr, N);//down
        metod(0, ll, pl, l, D, Arr, N); if(ll == pl){break;}//left
        metod(1, lu, pu, u, D, Arr, N);//up
        lr += 1; pr -= 1, r += 1;
        ld += 1; pd -= 1, d -= 1;
        ll -= 1; pl += 1, l -= 1;
        lu -= 1; pu += 1, u += 1;
    }
    printD(D, size);
}

void centr(int** Arr, int D[], int size)
{
    int N = 0, flag;
    int lr = size / 2 - 1, pr = size / 2 - 1, r = size / 2;
        int lu,     pu,     u;
        int ll,     pl,     l;
        int ld,     pd,     d;
    if (size % 2 == 0)
    {
        lr = size / 2 - 1, pr = size / 2 - 1, r = size / 2;
        lu = size / 2,     pu = size / 2,     u = size / 2;
        ll = size / 2,     pl = size / 2 - 1, l = size / 2 - 1;
        ld = size / 2 - 1, pd = size / 2,     d = size / 2 - 2;
        flag = 0;
    }
    if (size % 2 == 1)
    {
        lr = size / 2,     pr = size / 2,     r = size / 2;
        lu = size / 2,     pu = size / 2,     u = size / 2 + 1;
        ll = size / 2 + 1, pl = size / 2,     l = size / 2 - 1;
        ld = size / 2 - 1, pd = size / 2,     d = size / 2 - 1;
        flag = 1;
    }
    cout << endl;
    while(1)
    {
        metod(0, lr, pr, r, D, Arr, N); if((flag == 1)&&(size == 1 || lr == 0)){break;}//right
        metod(1, lu, pu, u, D, Arr, N);//up
        metod(0, ll, pl, l, D, Arr, N); if((ll == size - 1) && (flag == 0) ){break;}//left
        metod(1, ld, pd, d, D, Arr, N);//down
        lr -= 1; pr += 1, r += 1;
        lu += 1; pu -= 1, u += 1;
        ll += 1; pl -= 1, l -= 1;
        ld -= 1; pd += 1, d -= 1;
    }
    printD(D, size);
}

int main ()
{
    srand(time(0));
    int size;
    int metod;
    cout << "size: ";
    cin >> size;

    int** Arr = genRandMatrix(size);
    int D[size * size];
    printMatrix(Arr, size);

    cout << "1) right diagonals" << endl
         << "2) left diagonals"  << endl
         << "3) centr"           << endl
         << "4) left elements"   << endl
         << "enter: ";
    cin >> metod;
    if(metod == 1)
    {
        right_diagonals(Arr, D, size);
    }
    if(metod == 2)
    {
        left_diagonals(Arr, D, size);
    }
    if(metod == 3)
    {
        centr(Arr, D, size);
    }
    if(metod == 4)
    {
        left_elements(Arr, D, size);
    }

    for(int i = 0; i < size; i++)
            delete[] Arr[i];
    delete [] Arr;

    return 0;
}