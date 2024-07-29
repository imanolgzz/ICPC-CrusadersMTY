#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b,k;
  cin >> a >> b >> k;
  for(int i = 1; i<=k; i++){
    int output = a * i + b;
    cout << output << " ";
  }
  cout << "\n";
  return 0;
}