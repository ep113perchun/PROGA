#include <iostream>
#include <ctime>

using namespace std;

int** genRandMatrix(int size, int maxValue) {
     int ** arr = new int*[size + 1];
     arr[0][0] = size;
     for (int i = 1; i < size + 1; i++) {
         int arrLineLength = rand() % 10 + 1;
         arr[i] = new int[arrLineLength + 1];
         arr[i][0] = arrLineLength;
         for (int j = 1; j < arrLineLength + 1; j++) {
             arr[i][j] = rand() % 100;
         }
     }
     return arr;
}
void printMatrix(int** arr) {
     cout << arr[0][0] << endl;
     for (int i = 1; i < arr[0][0] + 1; i++) {
         cout << arr[i][0] << ": ";
         for (int j = 1; j < arr[i][0] + 1; j++) {
             cout << arr[i][j] << " ";
         }
         cout << endl;
     }
}

int main () {
    srand(time(0));
    int size = rand() % 10 + 1;
    int maxValue = 100;
    int** arr = genRandMatrix(size, maxValue);
    printMatrix(arr);
    for(int i = 0; i < size; ++i)
            delete[] arr[i];
    delete [] arr;
    return 0;
}