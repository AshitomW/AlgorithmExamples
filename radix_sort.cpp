#include <iostream>
#include <vector>
#include <algorithm>





void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); 
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    // We process from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(std::vector<int>& array){
    if (array.empty()){
        return;
    }

    int maxVal = *std::max_element(array.begin(),array.end());

    std::cout<< maxVal << std::endl; 
    // doing cst for every digiti

    for(int exp = 1; maxVal/exp>0;exp *=10){
        countingSort(array, exp);
    }


}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    for (int x : arr) std::cout << x << " ";
    return 0;
}
