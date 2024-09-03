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
  int N;
  cin >> N;
  if(N < 3){
    cout << N << endl;
    return 0;
  }
  int first = 1;
  int second = 2;
  for(int i = 3; i <= N; i++){
    int temp = second + first;
    first = second;
    second = temp; 
  }
  cout << second << endl;
  return 0;
}