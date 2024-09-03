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
  // setIO();
  int N, K;
  cin >> N >> K;
  cout << floor((K - N + 1) / (float) N) << endl; 
  return 0;
}