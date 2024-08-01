#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
void printVec(vector<T> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << ' ';
  }
  cout << '\n';
}

int minK(vector<int> &memo, int position, string &river, int jumpingDistance){
  if(position >= river.size()){
    return 0;
  }
  if(memo[position] != -1){
    return memo[position];
  }
  if(river[position] == 'C'){
    memo[position] = -2;
  } else if (river[position] == 'W'){
    memo[position] = minK(memo, position + 1, river, jumpingDistance);
    if(memo[position] != -2) {
      memo[position] = memo[position] + 1;
    }
  } else if (river[position] == 'L'){
    int minDistance = 1e6 + 1;
    for(int i = 1; i <= jumpingDistance; i++){
      int aux = minK(memo, position + i, river, jumpingDistance);
      if(aux != -2){
        minDistance = min(aux, minDistance);
      } else if (aux == 0){
        break;
      }
    }
    if(minDistance == 1e6 + 1) minDistance = -2;
    memo[position] = minDistance;
  }

  return memo[position];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n, m, k;
    cin >> n >> m >> k;
    string river = "L";
    string complement;
    cin >> complement;
    river = river + complement;
    vector<int> memo(n+1, -1);
    int answer = minK(memo, 0, river, m);
    if(answer != -2 && answer <= k){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}