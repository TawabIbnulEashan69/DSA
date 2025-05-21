#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void print_array(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    print_array(arr, size);

    insertion_sort(arr, size);

    cout << "Sorted array: ";
    print_array(arr, size);

    return 0;
}