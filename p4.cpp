//14-1-2026
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);

            }
        }
    }

    int count = 1;
    cout << "Frequency of elements: " << endl;

    for(int i = 0; i < n; i++){
        if(i < n-1 && arr[i] == arr[i+1]) {
            count++;
        }
        else {
            cout << arr[i] << " - " << count << " times" << endl;
            count = 1;
        }
    }
}
