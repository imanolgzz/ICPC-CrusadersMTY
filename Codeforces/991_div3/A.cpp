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
    int n,m;
    int res = 0, sum = 0;
    cin >> n >> m;
    bool flag = false;
    while(n--){
      string word;
      cin >> word;
      if(!flag){
        sum += word.size();
        if(sum <= m) {
          res++;
        } else {
          flag = true;
        }
      }
    }
    cout << res << endl;
  }
}