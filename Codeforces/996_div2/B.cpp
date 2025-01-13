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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
      cin >> b[i];
    }

    int negativeCount = 0;
    int negativeNum = 0;
    int minPositive = 1e9+7;
    for(int i = 1; i <= n; i++){
      int tmp = a[i] - b[i];
      if(tmp < 0){
        negativeCount++;
        negativeNum = tmp;
      } else {
        minPositive = min(minPositive, tmp);
      }
    }
    if(negativeCount <= 1 && negativeNum + minPositive >= 0){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

  } 
  return 0;
}