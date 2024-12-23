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
    int n,m,k;
    cin >> n >> m >> k;
    string res = "";
    vector<int>a(m+1);
    unordered_set<int> myAns;
    for(int i = 1; i <= m; i++){
      cin >> a[i];
    }
    for(int i = 1; i <= k; i++){
      int tmp;
      cin >> tmp;
      myAns.insert(tmp);
    }

    if(n == k){
      for(int i = 0; i < m; i++){
        res += "1";
      }
      cout << res << endl;
      continue;
    }
    if(k < n-1){
      for(int i = 0; i < m; i++){
        res += "0";
      }
      cout << res << endl;
      continue;
    }

    for(int i = 1; i <= m; i++){
      if(myAns.count(a[i]) > 0){
        res += "0"; 
      } else {
        res += "1";
      }
    }
    cout << res << endl;
  }
  return 0;
}