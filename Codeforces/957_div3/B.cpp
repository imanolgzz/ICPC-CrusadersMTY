#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int maxNum = 0;
    int output = 0;
    while(k--){
      int a;
      cin >> a;
      maxNum = max(a, maxNum);
      if(a == 1){
        output++;
      } else {
        output += 2 * a - 1;
      }
    }
    output = output - (2 * maxNum - 1);
    cout << output << endl;
  }
}