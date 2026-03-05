//21-1-2026
#include<iostream>
using namespace std;

int main(){

    string a;
    cout << "Enter a text: " << endl;
    cin >> a;


    string b;
    cout << "Enter a pattern: " << endl;
    cin >> b;


    int m=a.size();
    int n=b.size();

    int ans = -1;
    int index = -1;

    for(int i=0;i<(m-n)+1;i++){
       bool flag=true;
    for(int j=0;j<n&&flag==true;j++){
        if(a[j+i]!=b[j]){
            flag = false;
            break;
        }
    }
    if(flag==true){
        ans=i+1;
        index=i+1;
        break;
    }
  }
  cout << "Total count: "<< ans << endl;

  if(index != -1){
    cout << "Pattern found at index " << index << endl;
  }
  else{
    cout << "Pattern not found" << endl;
  }
}
