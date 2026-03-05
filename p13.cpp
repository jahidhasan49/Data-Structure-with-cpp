//28-1-2026
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pass = 0;
    bool swapped;

    // Bubble Sort (Descending Order)
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        pass++;

        for (int j = 0; j < n - i - 1; j++) {
            // descending order
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // Array after each pass
        cout << "After pass " << pass << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        // Early stopping
        if (!swapped) {
            break;
        }
    }

    cout << "\nTotal number of passes: " << pass << endl;

    cout << "Sorted array in descending order: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
