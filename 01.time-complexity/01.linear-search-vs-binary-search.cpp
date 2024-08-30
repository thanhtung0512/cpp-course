#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // for rand()
#include <chrono>   // for time measurement
using namespace std;
// Hàm tìm kiếm tuyến tính
bool linearSearch(const std::vector<int>& data, int target) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return true;
        }
    }
    return false;
}

// Hàm tìm kiếm nhị phân
bool binarySearch(const std::vector<int>& data, int target) {
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return true;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    const int N = 1000000000; // 10^9 phần tử
    std::vector<int> data(N);

    // Tạo ngẫu nhiên 10^9 phần tử
    for (int i = 0; i < N; ++i) {
        data[i] = rand();
    }

    // Phần tử cần tìm
    int target = data[rand() % N];  // Lấy phần tử ở giữa để tìm kiếm

    // Đo thời gian của Linear Search
    auto start = std::chrono::high_resolution_clock::now();
    bool foundLinear = linearSearch(data, target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> linearDuration = end - start;
    std::cout << "Linear Search - Found: " << std::boolalpha << foundLinear 
              << ", Time taken: " << linearDuration.count() << " seconds" << std::endl;

    std::cout << "Start sorting..." << endl;
    start = std::chrono::high_resolution_clock::now();
    // Sắp xếp lại vector để thực hiện Binary Search
    std::sort(data.begin(), data.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = end - start;
    std::cout << "End sorting" << endl << "Sorting time taken: " << sortDuration.count() << endl; 
    
    
    // Đo thời gian của Binary Search
    start = std::chrono::high_resolution_clock::now();
    bool foundBinary = binarySearch(data, target);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> binaryDuration = end - start;
    std::cout << "Binary Search - Found: " << std::boolalpha << foundBinary 
              << ", Time taken: " << binaryDuration.count() << " seconds" << std::endl;


    std::cout << linearDuration.count() << " = " << linearDuration.count() / binaryDuration.count() << " * " << binaryDuration.count() << endl;
    return 0;
}
