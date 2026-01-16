#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>



int partition(std::vector<int>& array, int low, int high){
    int pivot = array[high];
    int i = (low - 1);
    
    
    for(int j = low;j<=high-1;j++){
        if(array[j]<pivot){
            i++;
            std::swap(array[i],array[j]);
        }
    }
    
    std::swap(array[i+1],array[high]);
    return (i+1);

}



void quickSort(std::vector<int>& array, int low, int high){
    if (low<high){
        int pi = partition(array, low, high);
        quickSort(array, low, pi-1);
        quickSort(array,pi+1,high);
    }
}


int main() {
    std::vector<int> data = {10, 80, 30, 90, 40, 50, 70};
    
    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array: ";
    for (int x : data) std::cout << x << " ";
    return 0;
}
