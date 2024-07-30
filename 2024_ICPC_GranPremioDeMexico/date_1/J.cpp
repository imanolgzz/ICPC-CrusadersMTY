#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int minChanges(vector<vector<vector<int> > >&memo, string &input, int l, int r, int k){
  if(k == 0) return 0;
  // cout << l << " " << r << " " << k << endl;
  if(memo[l][r][k] != -1){
    return memo[l][r][k];
  }
  if((r - l) < (k - 1)){
    return 10000;
  }

  if(k == 1){
    return 0;
  }

  if(((r - l) == 2 && k == 3) || ((r - l) == 1 && k == 2)){
    return (int)(!(input[r] == input[l]));
  }


  memo[l][r][k] = min((minChanges(memo, input, l+1, r-1, k-2) + (int)(!(input[l] == input[r]))), min(minChanges(memo, input, l, r-1, k), minChanges(memo, input, l+1,r,k)));
  return memo[l][r][k];
}

int main(){
  int N,K;
  string S;
  cin >> N >> K >> S;
  vector<vector<vector<int> > >memo(N, vector<vector<int> >(N, vector<int>(K+1, -1)));
  cout << minChanges(memo, S, 0, S.size() - 1, K) << endl;
  return 0;
}