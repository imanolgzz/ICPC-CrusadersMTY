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
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+2);
    vector<int> b(n+2);
    vector<int> prices;
    for(int i = 1; i<= n; i++){
      cin >> a[i];
      prices.push_back(a[i]);
    }
    for(int i = 1; i<= n; i++){
      cin >> b[i];
      prices.push_back(b[i]);
    }
    sort(a.begin()+1, a.end()-1);
    sort(b.begin()+1, b.end()-1);
    sort(prices.begin(), prices.end());
    a[n+1] = INT_MAX;
    b[n+1] = INT_MAX;
    long long maxProfit = 0;
    long long price = 0;
    int p1, p2;
    p1 = p2 = 1;
    for(int price : prices){
      while(price > a[p1]){
        p1++;
      }
      while(price > b[p2]){
        p2++;
      }
      long long buyers = (n - p2 + 1);
      int madBuyers = (p1 - 1);
      madBuyers = madBuyers - (n - buyers);
      if(madBuyers <= k){
        maxProfit = max(maxProfit, buyers * price);
      }
    }

    cout << maxProfit << endl;    
  }
  return 0;
}