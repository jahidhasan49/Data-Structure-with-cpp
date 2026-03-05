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

    int cur_min;
    //Selection Sort
    for(int i=0; i<n; i++){
        cur_min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[cur_min]){
                cur_min = j;
            }
        }

        if(cur_min!=i){
            swap(arr[i], arr[cur_min]);
        }
    }

    cout << "Selection Sorted array: " << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}
