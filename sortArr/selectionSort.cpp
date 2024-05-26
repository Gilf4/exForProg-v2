#include <iostream>
#include <vector>

using namespace std;

//сортировки выбором ex73
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен местами минимального элемента с первым элементом
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}




void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

int main() { 
    int a[10] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    selectionSort(a, 10);
    printArray(a, 10);
    return 0;
}