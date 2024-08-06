// unsolved
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b){
  long long output = 1;
  while(b != 0){
    if(b&1){
      output = output * a % mod;
    }
    b = b >> 1;
    a = (long long)a * a % mod;
  }

  return output;
}

template <typename T>
void printVec(vector<T> &vec){
  for(T item : vec){
    cout << item << " ";
  }
  cout << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2;
  cin >> s1 >> s2;
  long long s1Size = s1.size(), s2Size = s2.size();
  vector<long long> hash1(s1Size);
  vector<long long> hash2(s2Size);
  hash1[0] = (long long) (s1[0] - 'a') + 1;
  hash2[0] = (long long) (s2[0] - 'a') + 1;
  for(long long i = 1; i < s1Size; i++){
    hash1[i] = (hash1[i-1] + (long long)(s1[i] - 'a' + 1) * power(256, i)) % mod;
  }

  for(long long i = 1; i < s2Size; i++){
    hash2[i] = (hash2[i-1] + (long long)(s2[i] - 'a' + 1) * power(256, i)) % mod;
  }
  printVec(hash1);
  printVec(hash2);

  long long minNumber, maxNumber;
  if(s1Size < s2Size){
    minNumber = s1Size;
    maxNumber = s2Size;
  } else {
    minNumber = s2Size;
    maxNumber = s1Size;

  }

  vector<long long>commonFactors;
  for(long long i = 1; i * i <= minNumber; i++){
    if(minNumber % i == 0 && maxNumber % i == 0){
      commonFactors.push_back(i);
      if(i * i != minNumber && maxNumber % (minNumber/i) == 0){
        commonFactors.push_back(minNumber / i);
      }
    }
  }


  long long counter = 0;
  for(long long factor : commonFactors){
    cout << endl << factor << " " << endl;
    long long hash = hash1[factor-1];
    for(long long i = factor; i < s1Size; i+= factor){
      long long tempHash = ((hash1[i + factor - 1] - hash1[i - 1]) % mod) / pow(256, i);
      cout << hash << " " << tempHash;
      if(tempHash != hash) goto final; 
    }
    
    for(long long i = 0; i < s2Size; i++){ 
      // here we need to implement the inverse modular multiplier
      long long tempHash = ((hash2[i + factor - 1] - hash2[i - 1]) % mod) / pow(256, i);
      cout << hash << " " << tempHash;
      if(tempHash != hash) goto final;
    }
    counter++;

    final:
    continue;
  }
  cout << '\n';
  cout << counter << '\n';


  return 0;
}