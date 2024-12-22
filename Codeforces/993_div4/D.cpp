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
    int n;
    cin >> n;
    vector<int> nums(n+1);
    unordered_set<int> uniqueNums;
    unordered_set<int> auxNums;
    
    for(int i = 1; i <= n; i++){
      cin >> nums[i];
      uniqueNums.insert(nums[i]);
    }

    for(int i = 1; i <= n; i++){
      if(uniqueNums.count(i) == 0){
        auxNums.insert(i);
      }
    }

    for(int i = 1; i <= n; i++){
      if(uniqueNums.count(nums[i]) == 0){
        cout << *auxNums.begin() << ' ';
        auxNums.erase(auxNums.begin()); 
      } else {
        cout << nums[i] << ' ';
        uniqueNums.erase(nums[i]);
      }
    }
    cout << endl;
  }
  return 0;
}