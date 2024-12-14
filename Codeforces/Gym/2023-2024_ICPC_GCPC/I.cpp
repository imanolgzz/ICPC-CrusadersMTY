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
  int n, q, i;
  cin >> n; 
  vector<int>frogs(n+1);
  vector<bool>freeSits(1e6 + 3e5, true);
  set<int> freeLilys;
  set<int>::iterator aux;
  for(int i = 1; i <= n; i++){
    cin >> frogs[i];
    freeSits[frogs[i]] = false;
  }
  for(int i = 1; i < (1e6 + 3e5); i++){
    if(freeSits[i]) freeLilys.insert(i);
  }
  cin >> q;
  while(q--){
    cin >> i;
    int currentPosition = frogs[i];
    aux = freeLilys.upper_bound(currentPosition);
    cout << *aux << '\n';
    frogs[i] = *aux;
    freeLilys.erase(aux);
    freeLilys.insert(currentPosition);
  }

  return 0;
}