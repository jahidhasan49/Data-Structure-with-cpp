//14-1-2026
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    cout << "sum of numbers: " << sum << endl;
    cout << "average of numbers: " << (float)sum / n << endl;
    cout << "maximum number: " << max << endl;
    cout << "minimum number: " << min << endl;

    return 0;
}
