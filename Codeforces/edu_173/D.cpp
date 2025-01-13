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
  redirectIO();
  int t;
  cin >> t;
  while(t--){
    ll l, r, G;
    cin >> l >> r >> G;
    ll lower = l / G;
    lower += (l % G > 0);
    ll upper = r / G;
    cout << "Find coprimes between " << lower << " and " << upper << endl;
  }
  return 0;
}