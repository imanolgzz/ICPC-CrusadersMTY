#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int n,p;
  int output = 0;
  cin >> n >> p;
  while(n--){
    int v;
    cin >> v;
    if(p >= v){
      output = max(v, output);
    }
  }
  cout << output << endl;
  return 0;
}