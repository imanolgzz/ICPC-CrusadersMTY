#include <bits/stdc++.h>
#define ll long long

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

const ll INF = 1e7;

void prllMat(vector<vector<ll>> &grid){
  for(ll i = 1; i < grid.size(); i++){
    for(ll j = 1; j < grid[0].size(); j++){
      cout << grid[i][j] << ' '; 
    }
    cout << endl;
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO();
  ll t;
  cin >> t;
  while(t--){
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<ll>> grid(n+1, vector<ll>(m+1));
    vector<ll> rows(n+1, 0);
    vector<ll> columns(m+1, 0);
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= m; j++){
        cin >> grid[i][j];
      }
    }
    grid[1][1] = INF;
    ll ei = 1, ej = 1;
    for(ll i = 0; i < s.size(); i++){
      if(s[i] == 'D'){
        ei++;
      } else {
        ej++;
      }
      grid[ei][ej] = INF;
    }
    s += ' ';
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= m; j++){
        if(grid[i][j] != INF) rows[i] += grid[i][j];
      }
    }

    for(ll j = 1; j <= m; j++){
      for(ll i = 1; i <= n; i++){
        if(grid[i][j] != INF) columns[j] += grid[i][j];
      }
    }
    ei = 1; ej = 1;
    ll base = 0;
    if(s[0] == 'D'){
      // base = rows[1];
    } else {
      // base = columns[1];
    }
    // cout << "Base " << base << endl;
    for(ll i = 0; i < s.size(); i++){
      if(s[i] == 'D'){
        grid[ei][ej] = base - rows[ei];
        columns[ej] += grid[ei][ej];
        rows[ei] += grid[ei][ej];
        // cout << ei << ' ' << ej << " -> " << grid[ei][ej] << endl;
        ei++;
      } else {
        grid[ei][ej] = base - columns[ej];
        rows[ei] += grid[ei][ej];
        columns[ej] += grid[ei][ej];
        // cout << ei << ' ' << ej << " -> " << grid[ei][ej] << endl;
        ej++;
      }
    }
    /*
    cout << "Rows" << endl;
    for(ll i = 1; i <= n; i++){
      cout <<  rows[i] << ' ';
    }

    cout << endl << "Columns" << endl;
    
    for(ll i = 1; i <= m; i++){
      cout <<  columns[i] << ' ';
    }
    cout << endl;
   */
   prllMat(grid);

  }
  
  return 0;
}