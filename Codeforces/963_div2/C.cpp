#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    vector<int> apartments(n + 1);
    for(int i = 1; i <= n; i++){
      cin >> apartments[i];
    }
    sort(apartments.begin(), apartments.end());
    int initRange = apartments[n];
    int endRange = apartments[n] + k - 1;
    int answer = 0;
    for(int i = 1; i < n; i++){
      int a = (apartments[n] - apartments[i]) / k;
      if(a & 1){
        a++;
      }
      int tempInit = apartments[i] + k * a;
      int tempEnd = apartments[i] + k * a + k - 1;
      // cout << initRange << " " << endRange << endl;
      // cout << tempInit << " " << tempEnd << endl;
      if(tempEnd < initRange || tempInit > endRange){
        answer = -1;
        break;
      } else {
        initRange = max(initRange, tempInit);
        endRange = min(tempEnd, endRange);
      }
      // aparment[i] + ak = apartments[n];
      // a = (apartments[n] - apartments[i])
    }
    if(answer == -1){
      cout << answer << '\n';
    } else {
      cout << initRange << '\n';
    }
    /*
    2 - 5 , 6 - 9
    3 - 7, 
    */

  }

  return 0;
}