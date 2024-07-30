// unsolved yet
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;


template <typename T>
void printVec(vector<T> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << '\n';
}

template <typename T>
void printMat(vector<vector<T> > &mat){
  for(int i = 0; i<mat.size(); i++){
    printVec(mat[i]);
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<long long> >bacteria(100, vector<long long>(20));
  bacteria[0][0] = 1;
  for(int i = 1; i<=99; i++){
    for(int j = 19; j >= 1; j--){
      bacteria[i][j] = bacteria[i-1][j-1];
      if(j == 6 || j == 10 || j == 14 || j == 18){
        bacteria[i][0] += 3 * bacteria[i][j];
      }
    }
  }

  for(int i = 0; i<=99; i++){
    int counter = 0;
    for(int j = 0; j < 20; j++){
      counter += bacteria[i][j];
    }
    cout << i << " - " << counter << endl;
  }
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
  }
  return 0;
}