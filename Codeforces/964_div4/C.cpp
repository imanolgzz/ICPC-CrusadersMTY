#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // setIO();
  int t;
  cin >> t;
  while(t--){
    int n, s, m;
    cin >> n >> s >> m;
    int maxNumber = 0;
    int leftPointer = 0;
    for(int i = 1; i <= n; i++){
      int l, r;
      cin >> l >> r;
      maxNumber = max(maxNumber, l - leftPointer);
      leftPointer = r;
    }
    maxNumber = max(maxNumber, m - leftPointer);
    if(maxNumber >= s){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}