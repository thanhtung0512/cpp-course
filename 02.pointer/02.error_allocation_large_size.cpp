#include <iostream>
using namespace std;

int main() {
    try {
        // Cấp phát bộ nhớ rất lớn trên Heap, có thể gây lỗi bad_alloc
        size_t largeSize = 1e10;  // 10 tỷ phần tử (khoảng 40GB nếu mỗi phần tử là 4 byte)
        int* largeArray = new int[largeSize];  // Thử cấp phát mảng lớn

        // Sử dụng mảng nếu cấp phát thành công
        for (size_t i = 0; i < 10; i++) {
            largeArray[i] = i;  // Gán thử giá trị vào mảng
            cout << largeArray[i] << " ";
        }
        
        // Giải phóng bộ nhớ
        delete[] largeArray;
    } catch (const bad_alloc& e) {
        // Bắt lỗi nếu không thể cấp phát bộ nhớ
        cerr << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
