#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define vll vector<ll>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

void solve(){
  ll n,m,k;
  cin >> n >> m >> k;
  vector<vll> original(n+1, vll(m+1));
  vector<vector<vll> > dp(n+1, vector<vll>(m+1, vll(m)));
  vector<vll> dpGlobal(n+1, vll(m+1, LONG_LONG_MAX));
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> original[i][j];
    }
  }

  for(int s = 0; s < m; s++){
    dp[1][1][s] = s * k + original[1][1+s];
    dpGlobal[1][1] = min(dpGlobal[1][1], dp[1][1][s]);
  }

  for(int i = 2; i <= n; i++){
    for(int s = 0; s < m; s++){
      dp[i][1][s] = s * k + original[i][1+s] + dpGlobal[i-1][1];
      dpGlobal[i][1] = min(dpGlobal[i][1], dp[i][1][s]);
    }
  }
  for(int j = 2; j <= m; j++){
    for(int s = 0; s < m; s++){
      int objColumn = (j + s);
      if(objColumn > m) objColumn -= m;
      dp[1][j][s] = dp[1][j-1][s] + original[1][objColumn];
      dpGlobal[1][j] = min(dpGlobal[1][j], dp[1][j][s]);
    }
  }

  for(int i = 2; i <= n; i++){
    for(int j = 2; j <= m; j++){
      for(int s = 0; s < m; s++){
        int objColumn = (j + s);
        if(objColumn > m) objColumn -= m;
        dp[i][j][s] = min(dp[i][j-1][s], dpGlobal[i-1][j] + s * k) + original[i][objColumn];
        dpGlobal[i][j] = min(dpGlobal[i][j], dp[i][j][s]);
      }
    }
  }
  cout << dpGlobal[n][m] << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO();
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  
  return 0;
}