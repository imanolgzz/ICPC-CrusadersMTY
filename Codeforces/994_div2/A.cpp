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
    vector<int> a(n+1);
    int start = 0, end = n;
    for(int i = 1; i<= n; i++){
      cin >> a[i];
    }
    while(start < n){
      if(a[start] == 0){
        start++;
      } else {
        break;
      }
    }
    while(end > 0){
      if(a[end] == 0){
        end--;
      } else {
        break;
      }
    }
    if(end < start || (end == start && a[end] == 0)){
      cout << 0 << endl;
      continue;
    }
    bool contains0 = false;

    for(int i = start; i <= end; i++){
      if(a[i] == 0){
        contains0 = true;
        break;
      }
    }

    if(contains0){
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }

  }
  return 0;
}