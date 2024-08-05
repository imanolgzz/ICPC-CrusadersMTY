#include <iostream>
using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  // setIO();
  int t;
  cin >> t;
  while(t--){
    string a, b;
    cin >> a >> b;
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b << '\n';
  }
  return 0;
}