//задачи из сборника

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 2. Создать массив из номеров нулевых элементов
void ex2(int arr[], int size) {
    int resSize = 0;
    vector<int> ans;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            ans.push_back(i);
        }
    }
}

// 3. Выяснить, какое число встречается раньше – положительное или отрицательное
string ex3(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) return "Положительное";
        if (arr[i] < 0) return "Отрицательное";
    }
    return "Нет положительных или отрицательных чисел";
}

// 4. Выяснить, будет ли последовательность возрастающей
bool ex4(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] <= arr[i - 1]) return false;
    }
    return true;
}

// 5. Создать массив из четных чисел
void ex5(int arr[], int size) {
    vector<int> ans;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            ans.push_back(arr[i]);
        }
    }
    if (ans.size()==0) {
        std::cout << "Четных чисел нет." << endl;
    }
}

// 6. Указать наименьшую длину числовой оси, содержащую все числа
int ex6(const int arr[], int size) {
    if (size == 0) return 0;
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return max - min;
}

// 7. Заменить все члены, большие данного Z, этим числом и подсчитать количество замен
int ex7(double arr[], int size, double Z) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > Z) {
            arr[i] = Z;
            count++;
        }
    }
    return count;
}

// 8. Найти количество членов последовательности, оканчивающейся нулем
int ex8(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) break;
        count++;
    }
    return count;
}

// 9. Подсчитать количество отрицательных, положительных и нулевых элементов
void ex9(int arr[], int size) {
    int negatives = 0, positives = 0, zeros = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) negatives++;
        else if (arr[i] > 0) positives++;
        else zeros++;
    }
    cout << negatives << ' ' << positives<< ' ' << zeros << endl;
}

// 10. Поменять местами наибольший и наименьший элементы
void ex10(double arr[], int size) {
    if (size == 0) return;
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
    double temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

// 11. Вывести только те числа, для которых выполняется условие a[i] ≤ i
void ex11(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] <= i) {
            cout << arr[i] << " ";
        }
    }
}

// 12. Указать числа, у которых остаток от деления на M равен L
void ex12(const int arr[], int size, int M, int L) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % M == L) {
            cout << arr[i] << " ";
        }
    }
}


int main() { 
    return 0;
}