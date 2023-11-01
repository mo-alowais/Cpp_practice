#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++)
    {
        
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    vector<int> arr = {2, 4, 1, 7, 3, 6};
    int n = arr.size();
    
    quickSort(arr, 0, n-1);
    
    for(auto x: arr)
        cout << x << endl;
    
    return 0;
    
}
