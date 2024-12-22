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
  unordered_map<char,char> translate;
  translate['q'] = 'p';
  translate['p'] = 'q';
  translate['w'] = 'w';
  int t;
  cin >> t;
  while(t--){
    string a, res = "";
    cin >> a;
    for(int i = a.size() - 1; i >= 0; --i){
      res += translate[a[i]];
    }
    cout << res << endl;
  }

  return 0;
}