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
  int T;
  cin >> T;
  while(T--){
    string s, t;
    cin >> s >> t;
    string output = "";
    int currentLetter = 0;
    for(int i = 0; i < s.size(); i++){
      bool flag = false;
      if(!(currentLetter < t.size())){
        flag = true;
      }
      if(s[i] == '?'){
        if(flag){
          output += 'a';
        } else {
          output += t[currentLetter];
          currentLetter++;
        }
      } else {
        output += s[i];
        if(!flag){
          if(s[i] == t[currentLetter]) currentLetter++;
        }
      }
    }
    if(currentLetter >= t.size()){
      cout << "YES" << endl;
      cout << output << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}