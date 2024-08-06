// unsolved;
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
  setIO();
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int ones = 0, ceros = 0;
    for(int i = 1; i <= n; i++){
      int temp;
      cin >> temp;
      if(temp == 1) ones++;
      if(temp == 0) ceros++;
    }
    cout << ones << " " << ceros << endl;
    int output = 0;

  }
  return 0;
}