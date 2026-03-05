//28-1-2026
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "enter number of elements" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter numbers: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    //Bubble Sort
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout << "Bubble Sorted array: " << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}
