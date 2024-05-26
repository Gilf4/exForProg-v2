#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i = size - 1; i > 0; --i){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
        
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}
