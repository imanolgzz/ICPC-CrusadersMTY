#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  setIO();
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    int maxVi = 0;
    for(int i = 0; i < n; i++){
      int li;
      cin >> li;
      vector<int>ai(li);
      for(int j = 0; j < li; j++){
        cin >> ai[j];
      }
      sort(ai.begin(), ai.end());

    }
  }
  return 0;
}