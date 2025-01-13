#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO();
  int t;
  cin >> t;
  while(t--){
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a - b) & 1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } 
  return 0;
}