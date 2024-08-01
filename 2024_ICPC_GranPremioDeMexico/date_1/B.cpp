#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int mod = 1e9+7;

class Mat{
  public:
    int rows, columns;
    vector<vector<int> >matrix;
    Mat(int _size){
      rows = _size;
      columns = _size;
      matrix = vector<vector<int> >(rows + 1, vector<int>(columns + 1));
    }
    Mat(int _rows, int _columns){
      rows = _rows;
      columns = _columns;
      matrix = vector<vector<int> >(rows + 1, vector<int>(columns + 1));
    }
    void identity(){
      if(rows != columns) return;
      for(int i = 1; i <= rows; i++){
        matrix[i][i] = 1;
      }
    }
    Mat operator*(Mat b){
      Mat res(rows);
      for(int i = 1; i <= res.rows; i++){
        for(int j = 1; j <= res.rows; j++){
          for(int k = 1; k <= res.rows; k++){
            res.matrix[i][j] = ((long long)res.matrix[i][j] + ((long long)matrix[i][k] * b.matrix[k][j]) % mod) % mod;
          }
        }
      }
      return res;
    }

    void print(){
      for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
          // cout << matrix[i][j] << " ";
          printf("%4d ", matrix[i][j]);
        }
        cout << '\n';
      }
      cout << flush;
    }
};


int main(){
  Mat states(20);
  for(int i = 1; i <= 19; i++){
    states.matrix[i][i+1] = 1;
    if(i == 6 || i == 10 || i == 14 || i == 18){
      states.matrix[i][1] = 3;
    }
  }
  Mat nullmat(20);
  nullmat.identity();
  // states.print();
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    Mat res(20);
    Mat aux = states;
    res.identity();
    while(N > 0){
      if(N & 1){
        res = res * aux;
      }
      aux = aux * aux;
      N = N >> 1;
    }
    long long output = 0;
    for(int i = 1; i <= 20; i++){
      output += (long long) res.matrix[1][i];
      output = output % mod;
    }
    cout << output << '\n';

  }

  return 0;
}