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
    vector<int>a(n+1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int median;
    if(n & 1){
      median = ceil(float(n) / 2);
    } else {
      median = n/2 + 1;
    }
    cout << a[median] << endl;
  }
  return 0;
}