//14-1-2026
#include<iostream>
using namespace std;

int main(){
  int n, i;
  bool isprime=true;
  cout << "Enter a number: " << endl;
  cin >> n;

      for(i=2;i<=n/2;i++){
      if(n%i==0){
        isprime=false;
        break;
      }

    }
      if(isprime==true){
        cout << n << " is a prime number" << endl;
      }
      else{
        cout << n << " is not a prime number" << endl;
      }

      return 0;

}
