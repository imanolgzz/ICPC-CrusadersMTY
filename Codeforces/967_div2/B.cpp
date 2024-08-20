#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(!(n & 1)){
      cout << -1 << '\n';
      continue;
    }
    vector<int>output(n+1);
    int currentNum = n;
    int leftPtr = 1;
    int rightPtr = n;
    while(leftPtr < rightPtr){
      output[leftPtr] = currentNum;
      currentNum--;
      output[rightPtr] = currentNum;
      currentNum--;
      leftPtr++;
      rightPtr--;
    }
    output[leftPtr] = 1;
    for(int i = 1; i <output.size(); i++){
      cout << output[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}