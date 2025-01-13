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
    int n;
    cin >> n;
    ll even = 0, odds = 0;
    for(int i = 1; i <= n; i++){
      int ai;
      cin >> ai;
      if(i & 1){
        odds += ai;
      } else {
        even += ai;
      }
    }
    
    ll oddsN, evenN;
    evenN = n / 2;
    oddsN = n - evenN;
    if(even % evenN == 0 && odds % oddsN == 0 && (even/evenN) == (odds/oddsN)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

}