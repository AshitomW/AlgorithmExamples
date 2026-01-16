#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Is the left child bigger? Grounded.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Is the right child even bigger? Also grounded.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the parent isn't the biggest, we swap until they learn who's boss
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// The main event
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Turning a messy array into a organized pile of numbers
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Yeeting the largest element to the back one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); // Fix the mess we just made at the top
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> data = {4, 10, 3, 5, 1};
    
    heapSort(data);
    
    cout << "Look at these sorted boys: ";
    printArray(data);
    
    return 0;
}
