#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

long long calculatePairs(long long objective, long long l1, long long r1, long long l2, long long r2){
  if(objective > r2) return 0;
  l2 = l2 + (objective - (l2 % objective));
  r2 = r2 - (r2 % objective);
  l1 = max(objective/l2, l1);
  r1 = min(l2, r1);
  cout << objective << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
  if(l1 > r1) return 0;

  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  redirectIO();
  int t;
  cin >> t;
  while(t--){
    long long k,l1,r1,l2,r2;
    long long res = 0;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    long long obj = 1;
    while(obj <= 1e9){
      res += calculatePairs(obj, l1,r1,l2,r2);
      obj *= k;
    } 
    /*
      3
      [5,7], [15,63]
      1, 3, 9, 27

      calc pair 1:


    */

  }
  return 0;
}