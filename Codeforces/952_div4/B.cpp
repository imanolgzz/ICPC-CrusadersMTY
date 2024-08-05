#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n == 3){
      cout << 3 << endl;
      continue;
    } else {
      cout << 2 << endl;
      continue;
    }
  }
  return 0;
}