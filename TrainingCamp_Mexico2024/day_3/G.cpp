#include <iostream>
#include <math.h>
 
using namespace std;
const int mod = 998244353;
 
int main(){
  int w,h, exponent;
  cin >> w >> h;
  exponent = w + h;
  long long output = 1;
  while(exponent > 0){
    if(exponent >= 16){
      output = (output * (1 << 16)) % mod;
      exponent -= 16;
    } else if(exponent >= 8){
      output = (output * (1 << 8)) % mod;
      exponent -= 8; 
    } else if(exponent >= 4){
      output = (output * (1 << 4)) % mod;
      exponent -= 4;
    } else if(exponent >= 2){
      output = (output * (1 << 2)) % mod;
      exponent -= 2;
    } else {
      output = output * 2 % mod;
      exponent -= 1;
    }
  }
 
  cout << output << endl;
  return 0;
}