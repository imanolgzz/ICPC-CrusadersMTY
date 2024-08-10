// unsolved
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    long long m;
    cin >> n >> m;
    map<long long, int> flowers;
    while(n--){
      long long a;
      cin >> a;
      flowers[a]++;
    }
    // 1 2 3
    long long max = 0;
    for(auto flower: flowers){
      if(flowers.find(flower.first - 1) != flowers.end()){
        
				// case it selects both key and key - 1
        // ax + (a - 1)y <= m (maximize)
        // ax + ay - y <= m
        // a(x + a) - y <= m
        // x <= flowers[a]
        // y <= flowers[b]
      }
      if(flowers.find(flower.first + 1) != flowers.end()){
        // case it selects key and key + 1
      }
      if(true){
        // case it selects just key
      }
    }
  }
  return 0;
}
