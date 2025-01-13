#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int calculateParts(int divisor, int num, vector<int> &dp){
  if(num == 1) return 0;
  if(num <= divisor){
    return 1;
  }
  if(dp[num] != -1) return dp[num]; 
  dp[num] = calculateParts(divisor, num/divisor, dp) + calculateParts(divisor, num - num/divisor, dp);
  return dp[num];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO(); 
  int t;
  cin >> t;
  while(t--){
    float n,k;
    cin >> n >> k;
    cout << ceil((n-1)/(k-1)) << endl;
  }
  return 0;
}