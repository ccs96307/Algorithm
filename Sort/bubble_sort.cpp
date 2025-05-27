#include<iostream>
#include<vector>


int main() {
    // Init
    int count = 0;
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, 3, 77, 23, 13, 8, 99, 72, 56, 3, 88, 33};

    for (int i=0; i<arr.size(); ++i) {
        for (int j=0; j<arr.size()-i-1; ++j) {
            ++count;
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }

    for (int &n: arr) {
        std::cout << n << std::endl;
    }

    std::cout << "Count: " << count << std::endl;

    return 0;
}