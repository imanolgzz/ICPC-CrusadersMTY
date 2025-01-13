#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  redirectIO();
  for(int i = 1; i <= 1000; i++){
    cout << 7 * i << endl;
  }
  return 0;
}