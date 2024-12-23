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
    int n,a,b,c;
    int res = 0;
    cin >> n >> a >> b >> c;
    int sum = a + b + c;
    res = (n/sum)*3;
    n = n%sum;
    if(n > 0){
      n -= a;
      res++;
    }
    if(n > 0){
      n -= b;
      res++;
    }
    if(n > 0){
      n -= c;
      res++;
    }
    cout << res << endl;
  }

  return 0;
}