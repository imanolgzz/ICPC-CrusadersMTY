#include <iostream>
#include <vector>
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
    unsigned long long n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<unsigned long long>a(n+1);
    vector<unsigned long long>p(n+1);
    for(int i = 1; i <= n; i++){
      cin >> p[i];
    }
    for(int i = 1; i<=n; i++){
      cin >> a[i];
    }
    unsigned long long maxBodya = 0, maxSasha = 0;
    unsigned long long sumCarry = 0;
    int counter = 0;
    while(counter < n && (k - counter) > 0){
      // cout << "sumCarry: " << sumCarry << " a[pb] " << a[pb] << " (k - counter) " << k - counter << endl;
      maxBodya = max(maxBodya, sumCarry + a[pb] * (k - counter));
      // cout << maxBodya << " ";
      sumCarry = sumCarry + a[pb];
      counter++;
      pb = p[pb];
    }
    // cout << '\n';
    counter = 0;
    sumCarry = 0;
    while(counter < n && (k - counter) > 0){
      maxSasha = max(maxSasha, sumCarry + a[ps] * (k - counter));
      // cout << maxSasha << ' ';
      sumCarry = sumCarry + a[ps];
      counter++;
      ps = p[ps];
    }
    // cout << '\n';
    // cout << maxBodya << ' ' << maxSasha << '\n';
    if(maxBodya == maxSasha){
      cout << "Draw" << '\n';
    } else if (maxBodya > maxSasha){
      cout << "Bodya" << '\n';
    } else {
      cout << "Sasha" << '\n';
    }
  }

  
  return 0;
}