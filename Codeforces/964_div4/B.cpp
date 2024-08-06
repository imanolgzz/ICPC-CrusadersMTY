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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int counter = 0;
    if(a1 > b1){
      if(a2 > b2 || a2 == b2){
        counter ++;
      }      
    }else if(a2 > b2){
      if(a1 == b1){
        counter ++;
      }
    }
    if(a1 > b2){
      if(a2 > b1 || a2 == b1){
        counter ++;
      }
    } else if(a2 > b1){
      if(a1 == b2){
        counter ++;
      }
    }
    if(a2 > b1){
      if(a1 > b2 || a1 == b2){
        counter ++;
      }
    } else if(a1 > b2){
      if(a2 == b1){
        counter ++;
      }
    }
    if(a2 > b2){
      if(a1 > b1 || a1 == b1){
        counter++;
      }
    } else if(a1 > b1){
      if(a2 == b2){
        counter ++;
      }
    }
    cout << counter << endl;
  }
  return 0;
}