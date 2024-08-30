#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Hàm đo tốc độ trích xuất từ Stack
void testStackAccess() {
    // Cấp phát mảng trên Stack
    int stackArray[1000000];  // Mảng với 1 triệu phần tử

    // Gán giá trị để chắc chắn bộ nhớ được sử dụng
    for (int i = 0; i < 1000000; i++) {
        stackArray[i] = i;
    }

    // Bắt đầu đo thời gian truy cập từ Stack
    auto start = high_resolution_clock::now();

    // Trích xuất giá trị từ mảng trên Stack
    volatile int sum = 0;  // Dùng volatile để tránh tối ưu hóa compiler
    for (int i = 0; i < 1000000; i++) {
        sum += stackArray[i];
    }

    // Kết thúc đo thời gian
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Stack Access Time: " << duration.count() << " microseconds" << endl;
}

// Hàm đo tốc độ trích xuất từ Heap
void testHeapAccess() {
    // Cấp phát mảng trên Heap
    int* heapArray = new int[1000000];  // Mảng với 1 triệu phần tử

    // Gán giá trị để chắc chắn bộ nhớ được sử dụng
    for (int i = 0; i < 1000000; i++) {
        heapArray[i] = i;
    }

    // Bắt đầu đo thời gian truy cập từ Heap
    auto start = high_resolution_clock::now();

    // Trích xuất giá trị từ mảng trên Heap
    volatile int sum = 0;  // Dùng volatile để tránh tối ưu hóa compiler
    for (int i = 0; i < 1000000; i++) {
        sum += heapArray[i];
    }

    // Kết thúc đo thời gian
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Heap Access Time: " << duration.count() << " microseconds" << endl;

    // Giải phóng bộ nhớ
    delete[] heapArray;
}

int main() {
    // Gọi các hàm để đo tốc độ trích xuất
    testStackAccess();
    testHeapAccess();

    return 0;
}
