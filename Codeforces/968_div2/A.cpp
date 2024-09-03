#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  // setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int leftPtr = 0, rightPtr = n - 1;
    bool flag = false;
    while(leftPtr < rightPtr){
      if(s[leftPtr] != s[rightPtr] && s[0] != s[rightPtr]){
        flag = true;
        break;
      }
      leftPtr++;
    } 
    if(flag){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}