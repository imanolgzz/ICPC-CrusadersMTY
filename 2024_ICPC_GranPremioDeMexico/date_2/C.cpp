#include <iostream>

using namespace std;

int main(){
  int q;
  cin >> q;
  while(q--){
    int n,t;
    cin >> n >> t;
    int objective = t - 1;
    int output = 0;
    if(objective == 0){
      cout << n << endl;
      continue;
    }
    for(int i = 1; i * i <= objective; i++){
      if (objective % i == 0){
        if(i <= n){
          output++;
        }
        if(i*i != objective){
          if(objective / i <= n){
            output++;
          }
        }
      }
    }
    cout << output << endl;
  }
}