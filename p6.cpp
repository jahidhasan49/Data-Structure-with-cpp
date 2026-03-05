//14-1-2026
#include<iostream>
using namespace std;

int main(){
    int n, max1, max2;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter numbers: " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    max1 = arr[0];
    max2 = arr[1];

    for(int i=0;i<n;i++){
        if(arr[i]>max1){
            max2 = max1;
            max1 = arr[i];
        }

        else if(arr[i]>max2 && arr[i]<max1){
            max2 = arr[i];
        }
    }

    cout << "The second largest number is: " << max2 << endl;
    cout << "The first largest number is: " << max1 << endl;
}
