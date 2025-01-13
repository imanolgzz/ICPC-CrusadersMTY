#include <bits/stdc++.h>
#define ll long long
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
    ll n, res = 1;
    cin >> n;
    while(n > 3){
      n = n / 4;
      res *= 2;
    }
    cout << res << endl;
  }

  return 0;
}