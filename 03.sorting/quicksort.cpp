#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Chọn phần tử cuối cùng làm pivot
    int i = (low - 1);      // Đặt i trước vị trí đầu tiên của dãy

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;            // Tăng chỉ số i
            swap(arr[i], arr[j]); // Hoán đổi arr[i] và arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về vị trí đúng
    return (i + 1);               // Trả về chỉ số của pivot
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pi là vị trí chỉ số của pivot
        int pi = partition(arr, low, high);

        // In mảng sau mỗi lần partition
        cout << "Array after partition with pivot index " << pi << ": ";
        printArray(arr, high + 1);

        // Gọi đệ quy quickSort cho hai phần bên trái và phải của pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
