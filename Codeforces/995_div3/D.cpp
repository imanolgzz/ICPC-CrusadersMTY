#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO();
  long long t;
  cin >> t;
  while(t--){
    long long n,x,y;
    long long sum = 0;
    cin >> n >> x >> y;
    vector<long long> a(n+1);
    for(long long i = 1; i <= n; i++){
      cin >> a[i];
      sum += a[i];
    }
    sort(a.begin()+1, a.end());
    long long temp = x;
    x = sum - y;
    y = sum - temp;
    long long res = 0;
    x = max(x, (long long)0);
    y = max(y, (long long)0);
    long long leftPtr = 1, rightPtr = a.size()-1;
    for(long long i = 1; i <= n; i++){
      long long tmpX = x - a[i];
      long long tmpY = y - a[i];
      tmpX = max(tmpX, (long long)0);

      if(tmpY <= 0){
        continue;
      }
      
      long long leftPtr = 1, rightPtr = a.size() - 1;
      
      while(leftPtr < rightPtr){
        long long mid = (leftPtr + rightPtr)/2;
        if(a[mid] < tmpX){
          if(leftPtr == mid){
            mid++;
          }
          leftPtr = mid;
        } else {
          rightPtr = mid;
        }
      }
      long long start = leftPtr;
      leftPtr = 1;
      rightPtr = a.size() - 1;
      while(leftPtr < rightPtr){
        long long mid = (leftPtr + rightPtr)/2;
        if(a[mid] > tmpY){
          rightPtr = mid; 
        } else {
          if(leftPtr == mid){
            if(a[mid+1] <= tmpY){
              rightPtr = mid;
              mid++;
            } else {
              rightPtr = mid;
            }
          }
          leftPtr = mid;
        }
      }
      long long end = leftPtr;
      if(start == end && (a[start] < tmpX || a[start] > tmpY)){
        continue;
      }
      res+= (end - start + 1);
      if(a[i] >= tmpX && a[i] <= tmpY){
        res--;
      }
    }
    cout << res/2 << endl;

  }

  return 0;
}