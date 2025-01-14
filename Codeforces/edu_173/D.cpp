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
    ll l, r, G;
    cin >> l >> r >> G;
    ll lower = l / G;
    lower += (l % G > 0);
    ll upper = r / G;
    ll k = upper-lower;
    ll A = -1, B = -1;
    while(k > 0){
      for(ll i = lower; i <= upper - k; i++){
        if(gcd(i,i+k) == 1){
          A = i;
          B = i+k;
          goto end;
        }
      }
      k--;
    }
end:
  if(A != -1 ){
    cout << A * G << ' ' << B * G << endl;
  } else if(lower == 1 && upper == 1) {
    cout << -A*G << ' ' << -B * G << endl;  
  } else {
    cout << "-1 -1" << endl;
  }

  }
  return 0;
}