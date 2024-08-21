// unsolved
#include <iostream>
#include <vector>
using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  setIO();
  int n,k;
  cin >> n >> k;
  vector<int> items(n+1);
  for(int i = 1; i <= n; i++){
    cin >> items[i];
  }
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  sort(items.begin(), items.end());
  int slices = 0;
  int value = items[n];
  int size = 1;
  int rightPointer = n;
  while(n > 0){
  }

  cout << slices << endl;
  return 0;
}