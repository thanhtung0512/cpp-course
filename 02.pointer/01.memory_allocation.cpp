#include <iostream>
using namespace std;

// Biến toàn cục (Global)
int globalVar = 10;

// Hàm cấp phát bộ nhớ trên Stack
void stackMemory() {
    int localVar = 20;  // Biến cục bộ, được lưu trữ trên Stack
    cout << "Stack Memory - Local Variable: " << localVar << endl;
}

// Hàm cấp phát bộ nhớ trên Heap
void heapMemory() {
    int* heapVar = new int(30);  // Cấp phát bộ nhớ động trên Heap
    cout << "Heap Memory - Dynamic Variable: " << *heapVar << endl;
    delete heapVar;  // Giải phóng bộ nhớ động để tránh rò rỉ bộ nhớ
}

// Biến tĩnh (Static)
void staticMemory() {
    static int staticVar = 40;  // Biến tĩnh, được lưu trữ trên vùng nhớ tĩnh
    cout << "Static Memory - Static Variable: " << staticVar << endl;
}

int main() {
    // Gọi hàm để xem cấp phát bộ nhớ
    cout << "Global Memory - Global Variable: " << globalVar << endl;
    stackMemory();
    heapMemory();
    staticMemory();
    
    return 0;
}
