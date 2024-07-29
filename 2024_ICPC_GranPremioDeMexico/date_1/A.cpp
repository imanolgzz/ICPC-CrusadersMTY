#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int minDifference(vector<int> &input, vector<vector<int> >&memo, int l, int r){
  if(l == r - 1){
    return abs(input[l] - input[r]);
  }
  if(memo[l][r] != -1){
    return memo[l][r];
  }

  memo[l][r] = min(abs(input[r]-input[l]), min(minDifference(input, memo, l, r-1), minDifference(input, memo, l+1, r)));
  return memo[l][r];

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q,l,r;
  cin >> n;
  vector<int>input(n+1);
  vector<vector<int> >memo(n+1, vector<int>(n+1, -1));
  for(int i = 1; i <= n; i++){
    cin >> input[i];
  }
  cin >> q;
  while(q--){
    cin >> l >> r;
    cout << minDifference(input, memo, l, r) << "\n";
  }

  return 0;
}