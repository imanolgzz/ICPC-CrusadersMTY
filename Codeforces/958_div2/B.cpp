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
    string s;
    cin >> n >> s;
    bool flag = false;
    if(s[0] == '1'  && s[n-1] == '1'){
      flag = true;
    }
    int count = 0;
    for(int i = 0; i < n - 1; i++){
      if(s[i] == '1' && s[i+1] == '1'){
        count++;
      }
    }

    if(count >= 2){
      flag = true;
    }
    if(count == 1 && (s[0] == '1'  || s[n-1] == '1')) flag = true;


    if(flag){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

  }
  return 0;

}