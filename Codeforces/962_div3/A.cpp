#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n % 4 == 0){
      cout << n / 4 << '\n';
    } else {
      int cows = n / 4;
      cout << cows + 1 << '\n';
    }
  }
  return 0;
}