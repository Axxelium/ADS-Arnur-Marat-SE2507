#include <iostream>
#include <vector>

// Bubble Sort: O(n^2) time, O(1) space
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort: O(n^2) time, O(1) space
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort: O(n^2) time, O(1) space
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> b = a;
    std::vector<int> c = a;

    std::cout << "Original:        ";
    printArray(a);

    bubbleSort(a);
    std::cout << "Bubble Sort:     ";
    printArray(a);

    selectionSort(b);
    std::cout << "Selection Sort:  ";
    printArray(b);

    insertionSort(c);
    std::cout << "Insertion Sort:  ";
    printArray(c);

    return 0;
}
