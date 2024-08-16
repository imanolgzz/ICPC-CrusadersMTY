// unsolved
#include <iostream>
#include <algorithm>
#include <vector>
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
    int n,m,k;
    cin >> n >> m >> k;
    int largeSide = max(n, m), smallSide = min(n,m);
    if(k > largeSide){
      cout << n * m << '\n';
      continue;
    } else if (k == 1){
      cout << 1 << '\n';
      continue;
    }



    //int rows = ((largeSide / k) + (largeSide % k));
    int rows = min(k, largeSide);
    // int columns = ((smallSide / k) + (smallSide % k));
    int columns = min(k, smallSide);
    cout << rows * columns << '\n';
  }
  return 0;
}
