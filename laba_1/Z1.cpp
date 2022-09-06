#include <iostream>
#include <ctime>

using namespace std;

int* genRandArray(int size, int maxValue) {
     int * arr = new int(size + 1);
     arr[0] = size;
     for (int i = 1; i < size + 1; i++) {
         arr[i] = rand() % maxValue;
     }
     return arr;
}
void print(int* arr) {
     int SIZE = arr[0] + 1;
     cout << arr[0] << ": ";
     for (int i = 1; i < SIZE; i++) {
         cout << arr[i] << " ";
     }  
}

int main () {
    srand(time(0));
    int size = rand() % 10 + 1;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete [] arr;
    return 0;
}