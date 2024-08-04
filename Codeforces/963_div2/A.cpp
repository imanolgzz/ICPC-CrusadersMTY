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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a, b, c, d;
    a = b = c = d = 0;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == 'A'){
        a++;
      } else if(s[i] == 'B'){
        b++;
      } else if(s[i] == 'C'){
        c++;
      } else if(s[i] == 'D'){
        d++;
      }
    }
    int maximum = min(a, n) + min(b, n) + min(c, n) + min(d, n);
    cout << maximum << '\n';
  }

  return 0;
}