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
    string n;
    int result = 0;
    cin >> n;
    for(char item : n){
      result = result + (int)(item - '0');
    }
    cout << result << endl;
  }
  return 0;
}