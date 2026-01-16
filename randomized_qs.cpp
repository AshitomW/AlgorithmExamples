#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//Lomuto partition scheme
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Random Pivot Selection
int partition_r(std::vector<int>& arr, int low, int high) {
    // Generate a random number between low and high
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    int random = dis(gen);

    // Swap random pivot with the last element
    std::swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition_r(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int x : arr) std::cout << x << " ";
    
    return 0;
}
