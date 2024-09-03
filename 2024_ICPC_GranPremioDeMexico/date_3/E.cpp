#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

void rotate(vector<vector<int> > & matrix){
  vector<vector<int> > tempMatrix(matrix.size(), vector<int>(matrix[0].size()));
  for(int i = 1; i < matrix.size(); i++){
    for(int j = 1; j < matrix[0].size(); j++){
      tempMatrix[matrix.size() - j][i] = matrix[i][j];
    }
  }
  for(int i = 1; i < matrix.size(); i++){
    for(int j = 1; j < matrix[0].size(); j++){
      matrix[i][j] = tempMatrix[i][j];
    }
  }
}

bool validate(vector<vector<int> > & matrix){
  bool flag = true;
  for(int i = 1; i < matrix.size(); i++){
    for(int j = 2; j < matrix[0].size(); j++){
      if(matrix[i][j] >= matrix[i][j-1]){
        continue;
      } else {
        flag = false;
        break;
      }
    }
  }
  if(flag){
    for(int i = 1; i < matrix.size(); i++){
      for(int j = 2; j < matrix[0].size(); j++){
        if(matrix[j][i] >= matrix[j-1][i]){
          continue;
        } else {
          flag = false;
          break;
        }
      }
    }
  }
  return flag;
}

int main(){
  // setIO();
  int N;
  cin >> N;
  vector<vector<int> > matrix(N+1, vector<int>(N+1));
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> matrix[i][j];
    }
  }
  int counter = 0;
  while(!validate(matrix)){
    counter++;
    rotate(matrix);
  }
  cout << counter << endl;
  return 0;
}