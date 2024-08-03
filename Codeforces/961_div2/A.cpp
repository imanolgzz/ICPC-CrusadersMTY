#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int minDiagonals = 0;
    int diagonals = 2 * n;
    int maximize = n + 1;
    // let´s calculate the number of combinations for each diagonal
    while(k > 0){
      int initRange = max(1, maximize - n);
      int endRange = min(n, maximize - 1);
      int combinations = endRange - initRange + 1;
      k = k - combinations;
      minDiagonals++;
      if(maximize != n + 1){
        if(k > 0){
          k = k - combinations;
          minDiagonals++;
        }
      }
      maximize--;
    }
    cout << minDiagonals << '\n';
  }
  return 0;
}