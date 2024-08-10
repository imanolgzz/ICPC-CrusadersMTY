// unsolved;
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int mod = 1e9+7;
vector<int> factorials(2e5 + 1);

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int power(int a, int b){
  int output = 1;
  while(b > 0){
    if(b&1){
      output = ((long long)output * a)% mod;
    }
    a = a * a;
    b = b >> 1;
  }
  return output;
}

int modularInverse(int a){
  return power(a,mod-2);

}

int factorial(int num){
  if(factorials[num] != 0){
    return factorials[num];
  }

  factorials[num] = ((long long) num * factorial(num-1)) % mod;
  return factorials[num];
}

int comb(int a, int b){
  // n! / (n-r)! r!
  int output = ((long long)((long long)factorial(a) * modularInverse(factorial(b)))% mod * modularInverse(factorial(a-b))) % mod; 
  return output;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  setIO();
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int ones = 0, ceros = 0;
    for(int i = 1; i <= n; i++){
      int temp;
      cin >> temp;
      if(temp == 1) ones++;
      if(temp == 0) ceros++;
    }
    cout << ones << " " << ceros << endl;
    int output = 0;
    int start = k/2 + 1;
    for(int i = start; i <=ones; i++){
      output =  (output + comb(k, i)) % mod;
    }
    cout << output << endl;

  }
  return 0;
}
