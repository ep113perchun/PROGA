#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

/*ВАРИАНТ  №3
Для каждого пункта задания написать подпрограмму - функцию
- сформировать    целочисленную матрицу    А(4х4);
-найти в матрице количество нулевых элементов;
-уменьшить  все положительные элементы матрицы на число, равное 2.*/

void fillarray(int arr[4][4], int row, int col)    // заполняет рандомными числами
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 101 - 50;
            cout << arr[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << "___________________________" << endl;
}

int handwork(int arr[4][4], int row, int col)           // ручной ввод
{
    int a[4][4];
    system("cls");      // Очистка экрана

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("\n Введите элемент a[%d][%d]: ", i, j);
            cin >> arr[i][j];
        }
    }
    //вывод матрицы
    system("cls");      // Очистка экрана
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
    return 0;
}

void file(int arr[4][4], int row, int col)            // перезаписывает числа в файле
{
    setlocale(0, "");
    string path = "myFile.txt";
    ofstream fout;

    fout.open(path);					// стирает файлы и переписывает           //	fout.open(path, ofstream::app);		// добавляет файлы

    if (!fout.is_open())
    {
        cout << "ошибка открытия файла!" << endl;
    }
    else
    {
        cout << "Введите данные в файл: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("Введите число [%d][%d]: ", i, j);
                int a;
                cin >> a;
                fout << a << "\n";
            }
        }
    }
}

void readfile(int arr[4][4], int row, int col)
{
    setlocale(0, "ru");

    string path = "myFile.txt";

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        system("cls");  // очищаем экран
        string str;

        for (int i = 0; i < 4 && (!fin.eof()); i++) // пока файл НЕ пустой
        {
            for (int j = 0; j < 4; j++)
            {
                {
                    fin >> str;
                    cout << str << "\t";
                }
            }
            cout << endl;
        }
    }
    fin.close();	// освобождение ресурсов
}

void two(int arr[4][4], int row, int col)    // +2
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > 0)
            {
                arr[i][j] = arr[i][j] + 2;
                cout << arr[i][j];
                cout << "\t";
            }
            else
            {
                cout << arr[i][j];
                cout << "\t";
            }
        }
        cout << endl;
    }
    cout << "___________________________" << endl;
}

void menu(int arr[N][N], int N){
    int key;
    cout << endl;
    cout << "1. Генератор случайных чисел" << endl;
    cout << "2. Ручной ввод" << endl;
    cout << "3. Заполнение из файла" << endl;
    cin >> key;
    switch (key)
    {
    case 1:
        fillarray(arr, N, N);
        break;
    case 2:
        handwork(arr, N, N);
        break;
    case 3:
        file(arr, N, N);
        readfile(arr, N, N);
        break;
    
    default:
        cout << "Вы ввели неверный пункт меню" << endl;
        break;
    }

}

int main()
{
    srand(time(NULL));
    int N = 4;
    int arr[N][N];
    menu(arr, N);
    return 0;
    //setlocale(0, "");
    // void print_menu();
    // {
    //     //system("cls");  // очищаем экран
    //     printf("1. Выбор способа создания массива\n");
    // }
    // int n, m;
    // cin >> m;
    // int arr[4][4];
    // switch (m)
    // {
    // case 1:
    //     //1system("cls");  // очищаем экран
    //     printf("1. Генератор случайных чисел\n");
    //     printf("2. Ручной ввод\n");
    //     printf("3. Заполнение из файла\n");
    //     cin >> n;
    //     system("cls");  // очищаем экран
    //     switch (n)
    //     {
    //     case 1:
    //         fillarray(arr, 4, 4);
    //         cout << "Все положительные элементы массива увеличить на 2: " << endl;
    //         two(arr, 4, 4);
    //         break;
    //     default:
    //         cout << "Вы ввели неверный пункт меню" << endl;
    //     case 2:
    //         handwork(arr, 4, 4);
    //         cout << "Все положительные элементы массива увеличить на 2: " << endl;
    //         two(arr, 4, 4);
    //     }
    //     break;
    // case 3:
    //     file(arr, 4, 4);
    //     readfile(arr, 4, 4);
    //     cout << "Все положительные элементы массива увеличить на 2: " << endl;
    //     two(arr, 4, 4);
    // default:
    //     cout << "Вы ввели неверный пункт меню" << endl;
    // }
}
