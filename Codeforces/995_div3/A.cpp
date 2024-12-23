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
    int n;
    cin >> n;
    vector<int> a(n+2);
    vector<int> b(n+2);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
      cin >> b[i];
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
      if(a[i] - b[i+1] > 0){
        res += (a[i] - b[i+1]);
      }
    }
    cout << res << endl;

  }
  return 0;
}