//14-1-2026
#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "enter a number: " << endl;
  cin >> n;

  if(n%2==0){
    cout << "The number is even" << endl;
  }

  else if(n%2!=0){
    cout << "The number is odd" << endl;
  }

  if (n>0){
    cout << "The number is positive" << endl;
  }

  else if(n<0){
    cout << "The number is negative" << endl;
  }

  else{
    cout << "The number is zero" << endl;
  }

  int i, count=0;
  for(i=0;n!=0;i++){
    n/=10;
    count++;
  }

  cout << "The number of digits: " << count << endl;


}
