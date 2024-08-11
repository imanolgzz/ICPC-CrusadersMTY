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
  setIO();
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
    int rows = ((largeSide - ((largeSide - 1) / k + 1)) + ceil((largeSide - 1) / float(k)));
    // int columns = ((smallSide / k) + (smallSide % k));
    int columns = ((smallSide - ((smallSide - 1) / k + 1)) + ceil((smallSide - 1) / float(k)));
    cout << rows << " " << columns << endl;
  }
  return 0;
}
