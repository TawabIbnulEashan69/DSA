#include <iostream>
using namespace std;

void selection_sort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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

    selection_sort(arr, size);

    cout << "Sorted array: ";
    print_array(arr, size);

    return 0;
}