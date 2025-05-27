#include<iostream>
#include<vector>


int partition(std::vector<int> &arr, int left, int right, int &count) {
    int pivot = arr[right];
    int next = left - 1;

    for (int i=left; i<right; ++i) {
        ++count;
        if (arr[i] <= pivot) {
            ++next;
            std::swap(arr[i], arr[next]);
        }
    }

    ++next;
    std::swap(arr[next], arr[right]);
    return next;
}



void quickSort(std::vector<int> &arr, int left, int right, int &count) {
    if (left < right) {
        int pivot = partition(arr, left, right, count);

        quickSort(arr, left, pivot - 1, count);
        quickSort(arr, pivot + 1, right, count);
    }
}


int main() {
    // Init
    int count = 0;
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, 3, 77, 23, 13, 8, 99, 72, 56, 3, 88, 33};

    quickSort(arr, 0, arr.size() - 1, count);

    for (int &n: arr) {
        std::cout << n << std::endl;
    }

    std::cout << "Count: " << count << std::endl;

    return 0;
}