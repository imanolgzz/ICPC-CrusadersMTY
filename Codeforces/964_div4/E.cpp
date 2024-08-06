#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

vector<int>steps(2e5+1);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // setIO();
  unsigned long long t;
  cin >> t;
  while(t--){
    unsigned long long l,r;
    cin >> l >> r;
    unsigned long long counter = 0;
    unsigned long long minor = l;
    unsigned long long next = minor+1;
    unsigned long long temp = minor;
    while(minor > 0){
      minor = minor / 3;
      next = next * 3;
      counter++;
    }
    while(next > 0){
      next = next / 3;
      counter++;
    }
    for(unsigned long long i = temp + 2; i <= r; i++){
      unsigned long long aux = i;
      if(steps[i] != 0){
        counter += steps[i];
        continue;
      }
      unsigned long long memo = 0;
      while(aux > 0){
        if(steps[aux] != 0){
          counter += steps[aux];
          memo += steps[aux];
          break;
        }
        aux = aux / 3;
        counter++;
        memo++;
      }
      steps[i] = memo;
    }
    cout << counter << endl;

  }
  return 0;
}