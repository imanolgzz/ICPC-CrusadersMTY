#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>

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
    int temp = n;
    unordered_map<int, int>numbers;
    while(n--){
      int a;
      cin >> a;
      numbers[a]++;
    }
    int maxNum = 0;
    for(auto item : numbers){
      maxNum = max(maxNum, item.second);
    }
    cout << temp - maxNum << '\n';
  }
  return 0;
}