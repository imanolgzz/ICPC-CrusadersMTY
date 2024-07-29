#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int vectorSize = 1e6;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<bool> stones(vectorSize+1);
  int n;
  cin >> n;
  bool winner = 1;
  int upper = 0;
  for(int i = 1; i <= n; i++){
    int tower;
    cin >> tower;
    stones[tower] = true;
    upper = max(upper, tower); 
  }
  for(int i = 1; i <= upper; i++){
    if(stones[i] == false){
      winner = !winner;
      break;
    } else {
      winner = !winner;
    }
  }

  if(winner == 0){
    cout << "Alicius\n";
  } else {
    cout << "Bobius\n";
  }

  return 0;
}