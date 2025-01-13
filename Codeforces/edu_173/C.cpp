#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int minSum(vector<int> &nums){
  int globalMin = 0;
  int currentMin = 0;
  for(int i = 0; i < nums.size(); ++i){
    currentMin += nums[i];
    globalMin = min(currentMin, globalMin);
    if(currentMin > 0) currentMin = 0;
  }

  return globalMin;
}

int maxSum(vector<int> &nums){
  int globalMax = 0;
  int currentMax = 0;
  for(int i = 0; i < nums.size(); ++i){
    currentMax += nums[i];
    globalMax = max(currentMax, globalMax);
    if(currentMax < 0) currentMax = 0;
  }

  return globalMax;
}

pair<int,int> constraintsFromPivot(vector<int> &nums, int pivot){
  int min1 = nums[pivot], max1 = nums[pivot], min2 = 0, max2 = 0;
  int current = nums[pivot];
  // cout << "N: " << nums[pivot] << endl;
  for(int i = pivot-1; i >= 0; i--){ 
    current += nums[i];
    min1 = min(min1, current);
    max1 = max(max1, current);
  }
  // cout << "1: " << min1 << ' ' << max1 << endl;
  current = 0;
  for(int i = pivot + 1; i < nums.size(); i++){ 
    current += nums[i];
    min2 = min(min2, current);
    max2 = max(max2, current);
  }
  // cout << "2: " << min2 << ' ' << max2 << endl;
  return pair<int,int>(min1 + min2, max1 + max2);
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
    vector<int> a(n+1);
    unordered_set<int> sums;
    vector<int> ans;
    for(int i = 1; i <= n; ++i){
      cin >> a[i];
    }
    int currentSum = 0, specialIndex = -1;
    sums.insert(currentSum);
    int i = 1;
    int side = 0;
    vector<vector<int> > nums(2, vector<int>());
    while(i <= n){
      if(a[i] != -1 && a[i] != 1) {
        if(currentSum != 0)
          nums[side].push_back(currentSum);
        currentSum = 0;
        specialIndex = i;
        i++;
        side = 1;
        continue;
      }

      if(a[i] + a[i-1] == 0){
        nums[side].push_back(currentSum);
        currentSum = a[i];
        i++;
        continue;
      }
      currentSum += a[i];
      i++;
    }

    if(currentSum != 0)
      nums[side].push_back(currentSum);

    int left, right;
    left = minSum(nums[0]);
    right = maxSum(nums[0]);
    for(int i = left; i <= right; ++i){
      sums.insert(i);
    }
    left = minSum(nums[1]);
    right = maxSum(nums[1]);
    for(int i = left; i <= right; ++i){
      sums.insert(i);
    }
    if(specialIndex != -1){
      pair<int,int> tmp = constraintsFromPivot(a, specialIndex);
      // cout << "Pivot: " << tmp.first << ' ' << tmp.second << endl;
      for(int i = tmp.first; i <= tmp.second; ++i){
        sums.insert(i);
      }
    }

    for(auto num : sums){
      ans.push_back(num);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
      cout << ans[i] << ' ';
    }
    cout << endl;

  }
  return 0;
}