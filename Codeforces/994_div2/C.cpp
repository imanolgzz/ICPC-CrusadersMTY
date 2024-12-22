#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int mex(int a, int b, int c){
  if(a == 0 || b == 0 || c == 0){
    if(a == 1 || b == 1 || c == 1){
      if(a == 2 || b == 2 || c == 2){
        return 3;
      }  else {
        return 2;
      }
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

int mex(int a, int b){
  if(a == 0 || b == 0){
    if(a == 1 || b == 1){
      return 2;
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO(); 
  int t;
  cin >> t;
  
  while(t--){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> res(n+1);
    bool flag = true;
    
    while(flag){
      int newMex = 0;
      flag = false;
      for(int i = 1; i<= n; i++){
        int prev = i-1, next = i+1;
        if(prev == 0) prev = n;
        if(next == n+1) next = 1; 
        if(i == x){
          newMex = mex(res[prev], res[next], res[y]);
        } else if(i == y) {
          newMex = mex(res[prev], res[next], res[x]); 
        } else {
          newMex = mex(res[prev], res[next]);
        }

        if(newMex != res[i]) flag = true;
        res[i] = newMex;
      }
    }
    for(int i = 1; i <= n; i++){
      cout << res[i] << ' ';
    }
    cout << endl;

  }

  return 0;
}