#include <iostream>
#include <vector>

using namespace std;

vector<long long>sieve(long long n){
  vector<long long> notPrimes(n + 1, 1);
  vector<long long> primes(1);
  primes[0] = 2;
  notPrimes[1] = 0;
  for(long long i = 4; i <= n; i +=2){
    notPrimes[i] = 0;
  }
  for(long long i = 3; i <= n; i += 2){
    if(notPrimes[i] == 1){
      primes.push_back(i);
      for(long long j = 3; i * j <= n; j+= 2){
        notPrimes[j*i] = 0;
      }
    }
  }
  return primes;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("primes.txt", "w", stdout);
  long long n;
  cin >> n;
  vector<long long>primes = sieve(n);
  for(long long i = 0; i < primes.size(); i++){
    cout << primes[i] << ' ';
    if((i+1) % 10 == 0) cout << '\n';
  }
  
  return 0;
}