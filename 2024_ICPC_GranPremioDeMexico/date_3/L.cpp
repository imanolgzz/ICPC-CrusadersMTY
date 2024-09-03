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
  setIO();
  int N;
  cin >> N;
  vector<int> bits(33);
  for(int i = 1; i <= N; i++){
    int num;
    cin >> num;
    int t = 0;
    while(num > 0){
      if(num & 1){
        bits[t]++;
      }
      num = num >> 1;
      t++;
    }
  }
  for(int i = 1; i <= N; i++){
    int num = 0;
    for(int i = 32; i >= 0; i--){
      num = num << 1;
      if(bits[i] > 0){
        num++;
        bits[i]--;
      }
    }
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}