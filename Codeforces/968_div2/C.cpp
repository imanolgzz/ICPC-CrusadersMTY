#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  // setIO();
  int t;
  cin >> t;
  // maximize the pairs i,j such that
  // there exist a pair k, k+1 inside [i,j-1] such that s[k] != s[k+1]
  // and s[k] != s[i] or s[k+1] != s[j]
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> letters(26);
    for(int i = 0; i < n; i++){
      int letter = (int)(s[i] - 'a');
      letters[letter]++;
    }
    vector<pair<int, char> > lettersOrdered(26);
    for(int i = 0; i < 26; i++){
      lettersOrdered[i] = pair<int,int>(letters[i], (char)(i + 'a'));
    }
    sort(lettersOrdered.begin(), lettersOrdered.end());
    string res = "";
    vector<char> answer(n);
    int evenPointer = 0, oddPointer = 1;
    for(int i = 25; i >= 0; i--){
      while(lettersOrdered[i].first > 0){
        if(evenPointer < n){
          answer[evenPointer] = lettersOrdered[i].second;
          evenPointer += 2;
        } else {
          answer[oddPointer] = lettersOrdered[i].second;
          oddPointer += 2; 
        }
        lettersOrdered[i].first--;
      }
    }
    for(int i = 0; i < n; i++){
      res += answer[i];
    }

    cout << res << endl;
  }
  return 0;
}