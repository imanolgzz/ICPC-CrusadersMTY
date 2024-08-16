#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int>alice(n+1);
    vector<int>bob(n +1);
    for(int i = 1; i <= n; i++){
      cin >> alice[i];
    }
    for(int i = 1; i <= n; i++){
      cin >> bob[i];
    }

    bool flag = false;
    int l1P = 1;
    int l2P = 1;
    int r1P = n;
    int r2P = n;

    int turn = 0;
    /*
    1 2 3 4 5
    5 3 4 2 1

    */
    while((l1P < r1P) && (l2P < r2P)){
      if(alice[l1P] != bob[l2P] && alice[l1P] != bob[r2P]){
        flag = true;
        break;
      } else if(alice[r1P] != bob[l2P] && alice[r1P] != bob[r2P]){
        flag = true;
        break;
      }

      if(alice[l1P] == bob[l2P]){
        l1P++;
        l2P++;
      } else if(alice[l1P] == bob[r2P]) {
        l1P++;
        r2P--;
      } else if(alice[r1P] == bob[l2P]) {
        r1P--;
        l2P++; 
      } else if (alice[r1P] == bob[r2P]){
        r1P--;
        r2P--;
      }
    }

    if(flag){
      cout << "Alice" << '\n';
    } else {
      cout << "Bob" << '\n';
    }

  }
  return 0;
}
