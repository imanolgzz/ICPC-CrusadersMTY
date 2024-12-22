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
    int m,a,b,c,res=0;
    int r1, r2;
    cin >> m >> a >> b >> c;
    r1 = r2 = m;
    res += min(r1, a);
    r1 -= min(r1, a);
    res += min(r2, b);
    r2 -= min(r2, b);
    res += min(r1, c);
    c -= min(r1, c);
    res += min(r2, c);
    c -= min(r2, c);
    cout << res << endl;
  }

  return 0;
}