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

breakpoint:
  while(t > 0){
    int n;
    string s;
    cin >> n >> s;
    // al p's have to appear after all s
    // validate that all p's appear after all s
    int start = -1;
    int countp = 0;
    int counts = 0;
    int sInside = 0;
    int pInside = 0;

    for(int i = 0; i < s.size(); i++){
      if(s[i] == 'p'){
        start = i;
        break;
      } else if (s[i] == 's'){
        counts++;
      }
    }

    for(int i = start; i < s.size(); i++){
      if(s[i] == 's'){
        cout << "NO" << endl;
        t--;
        goto breakpoint;
      }
      countp++;
    }

    if(counts >= 2 && countp >= 2){
      cout << "NO" << endl;
      t--;
      goto breakpoint;
    }

    if(start == -1){
      cout << "YES" << endl;
      t--;
      continue;
    }

    for(int i = 1; i < s.size() -1; i++){
      if(s[i] == 's'){
        sInside++;
      } else if(s[i] == 'p'){
        pInside++;
      }
    }

    if(sInside > 0 && pInside > 0){
      cout << "NO" << endl;
      t--;
      continue;
    }
    cout << "YES" << endl;
    t--;
    // s . p .
  }

  return 0;
}