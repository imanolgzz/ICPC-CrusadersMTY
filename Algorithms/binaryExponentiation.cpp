#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int powerRecursive(int a, int n){
    if(n == 0){
        return 1;
    }else if(n%2 == 0){
        long long tmp = powerRecursive(a, n/2);
        return tmp * tmp % mod;
    }else{
        long long tmp = powerRecursive(a, (n-1)/2);
        return a * tmp % mod * tmp % mod;
    }
}

long long powerIterative(int a, int b){
  long long output = 1;
  while(b > 0){
    if(b & 1){
      output = output * a % mod;
    }
    a = (long long)a * a % mod;
    b = b >> 1;
  }
  return output;
}

int main(){
  cout << powerIterative(5,1e9) << '\n';
  cout << powerRecursive(5, 1e9) << '\n';
}