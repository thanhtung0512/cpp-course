#include <iostream>
using namespace std;

// Hàm partition sử dụng Hoare's partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];  // Chọn pivot là phần tử giữa
    int left = low - 1;   // Con trỏ bắt đầu từ trước mảng
    int right = high + 1; // Con trỏ bắt đầu từ sau mảng

    while (true) {
        // Tìm phần tử bên trái lớn hơn hoặc bằng pivot
        do {
            left++;
        } while (arr[left] < pivot);

        // Tìm phần tử bên phải nhỏ hơn hoặc bằng pivot
        do {
            right--;
        } while (arr[right] > pivot);

        // Nếu hai con trỏ gặp nhau, dừng lại
        if (left >= right)
            return right;

        // Hoán đổi hai phần tử
        swap(arr[left], arr[right]);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pi là vị trí chỉ số của pivot
        int pi = partition(arr, low, high);

        // In mảng sau mỗi lần partition
        cout << "Array after partition with pivot index " << pi << ": ";
        printArray(arr, high + 1);

        // Gọi đệ quy quickSort cho hai phần bên trái và phải của pivot
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm main để chạy chương trình
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
