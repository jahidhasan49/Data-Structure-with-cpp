//28-1-2026
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter numbers: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    //Insertion Sort
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
        swap(arr[j], arr[j-1]);
        j--;
       }
    }

    cout << "Insertion Sorted array: " << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}
