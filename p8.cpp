//21-1-2026
#include<iostream>
using namespace std;
int main(){
    string t;
    cout << "Enter a text: " << endl;
    cin >> t;

    string p;
    cout << "Enter a pattern: " << endl;
    cin >> p;

    int count = 0;

    for(int i=0; i<=t.length()-p.length(); i++){
        bool flag = true;
        for(int j=0; j<p.length(); j++){
            if(t[i+j]!=p[j]){
                 flag = false;
                 break;
            }
        }
        if(flag==true){
            cout << "Pattern found at index: " << i+1 << endl;
            count++;
        }
}

    cout << "Repeat times: "<< count << endl;
}

