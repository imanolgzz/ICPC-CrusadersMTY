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
    ll n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(n);
    ll previous = -1;
    for(int i = 0; i < 64; i++){
      // get the current bit
      if((n & ((ll)1 << (ll)i)) > 0){
        if(previous != -1){
          n = n | ((ll)1 << (ll)previous);
        }
        n = n ^ ((ll)1 << (ll)i);
        if(n != 0) ans.push_back(n);
        previous = i;
      }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(ll num : ans){
      cout << num << ' ';
    }
    cout << endl;
  }
  return 0;
}