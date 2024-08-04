#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    int n;
    cin >> n;
    priority_queue<long long> oddsQueue;
    priority_queue<long long, vector<long long>, greater<long long> > pairsQueue;
    int odds = 0, pairs = 0;
    long long maxPair = 0;
    for(int i = 1; i<=n; i++){
      long long a;
      cin >> a;
      if(a & 1){
        odds++;
        oddsQueue.push(a);
      } else{
        maxPair = max(maxPair, a);
        pairs++;
        pairsQueue.push(a);
      }
    }
    if(odds == 0 || pairs == 0){
      cout << 0 << '\n';
      continue;
    }
    int counter = 0;
    bool flag = false;
    while(!pairsQueue.empty()){
      long long greaterOdd = oddsQueue.top();
      long long lowestPair = pairsQueue.top();
      if(greaterOdd > lowestPair){
        oddsQueue.push(lowestPair + greaterOdd);
        pairsQueue.pop();
        counter++;
        continue;
      }
      if(greaterOdd <= lowestPair){
        oddsQueue.pop();
        oddsQueue.push(maxPair + greaterOdd);
        counter++;
        continue;
      }
    }
    cout << counter << '\n';
  }
  return 0;
}