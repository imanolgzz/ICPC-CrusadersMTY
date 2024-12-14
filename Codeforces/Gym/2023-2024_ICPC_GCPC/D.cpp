#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}
 
int main(){
  // redirectIO();
  long long t,c,o,d,i;
  cin >> t >> c >> o >> d >> i;
  vector<long long> probabilities(501);
  while(t > 0 || c > 0 || o > 0 || d > 0 || i > 0){
    long long size = 0;
    if(t > 0){
      size = 4;
      t--;
    } else if(c > 0){
      size = 6;
      c--;
    } else if(o > 0){
      size = 8;
      o--;
    } else if(d > 0){
      size = 12;
      d--;
    } else if(i > 0){
      size = 20;
      i--;
    } 
 
    vector<long long> newProbabilities(501);
    for(long long i = 1; i <= size; i++){
      for(long long j = 0; j <= 500; j++){
        long long num = i + j;
        newProbabilities[num] += probabilities[j];
      }
    }
    vector<pair<long long,long long> > tmp(501, pair<long long,long long>());
    for(long long i = 0; i <= 500 ; i++){
      tmp[i].first = newProbabilities[i];
      tmp[i].second = i;
    }
    sort(tmp.begin(), tmp.end(), greater<pair<long long,long long> >());
    for(long long i = 0; i <= 500; i++){
      int priority = 500 - i;
      if(tmp[i].first == 0){
        break;
      } 
      newProbabilities[tmp[i].second] = priority;
    }
    probabilities = newProbabilities;
  }
  vector<pair<long long,long long> > output(501, pair<long long,long long>());
  for(long long i = 0; i <= 500 ; i++){
    output[i].first = probabilities[i];
    output[i].second = i;
  }
  sort(output.begin(), output.end(), greater<pair<long long,long long> >());
  for(pair<long long,long long> pair : output){
    if(pair.first == 0){
      break;
    }
    // cout << pair.second << " " << pair.first << endl;
    cout << pair.second << " ";
  }
  cout << endl;
 
  return 0;
 
}
