#include<stdio.h>
#include<iostream>
using namespace std;

int linearsearch(int arr[], int size,  int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << "elements: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int result = linearsearch(arr, size, target);

    if(result!=-1){
        cout << "Target found at index: " << result << endl;
    }
    else{
        cout << "Target not found." << endl;
    }

}
