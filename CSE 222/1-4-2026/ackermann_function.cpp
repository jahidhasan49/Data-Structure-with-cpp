#include <iostream>
using namespace std;

int ackermann(int a, int b) {
    if (a == 0) {
        return b + 1;
    } 
    else if (a != 0 && b == 0) {
        return ackermann(a - 1, 1);
    } 
    else if (a != 0 && b != 0) {
        return ackermann(a - 1, ackermann(a, b - 1));
    }
    return 0;
}

int main() {
    int a, b;
    
    cout << "Enter the value of a: ";
    cin >> a;
    
    cout << "Enter the value of b: ";
    cin >> b;
    
    int ans = ackermann(a, b);
    cout << "Result: " << ans << endl;

}