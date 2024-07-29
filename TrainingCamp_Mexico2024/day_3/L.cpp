#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
template <typename T>
void printVector(vector<T> &vector){
  for(T element : vector){
    cout << element << " ";
  }
  cout << endl;
}
 
long long getMax(vector<vector<long long> > &heights, vector<vector<long long> > &memo, int player, long long index){
  if(index > heights[0].size() - 1){
    return 0;
  }
  if(index == heights[0].size() - 1){
    memo[player][index] = heights[player][index];
    return memo[player][index];
  }
 
  if(memo[player][index] != -1) return memo[player][index];
 
  memo[player][index] = max(getMax(heights, memo, !player, index+2), getMax(heights, memo, !player, index+1)) + heights[player][index];
 
 
  return memo[player][index];
}
 
int main(){
  int n;
  cin >> n;
  vector<vector<long long> >heights(2, vector<long long>(n+1));
  vector<vector<long long> >maxHeights(2, vector<long long>(n+1, -1));
  for(int i = 1; i <= n; i++){
    long long player;
    cin >> player;
    heights[0][i] = player;
  }
 
  for(int i = 1; i <= n; i++){
    long long player;
    cin >> player;
    heights[1][i] = player;
  }
 
  cout << max(getMax(heights, maxHeights, 0, 1), getMax(heights, maxHeights, 1, 1)) << endl;
  return 0;
}