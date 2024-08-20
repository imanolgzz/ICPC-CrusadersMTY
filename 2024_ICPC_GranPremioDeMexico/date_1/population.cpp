#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Mat{
  public:
    int rows, columns;
    vector<vector<long double> >matrix;
    Mat(int _size){
      rows = _size;
      columns = _size;
      matrix = vector<vector<long double> >(rows + 1, vector<long double>(columns + 1));
    }
    Mat(int _rows, int _columns){
      rows = _rows;
      columns = _columns;
      matrix = vector<vector<long double> >(rows + 1, vector<long double>(columns + 1));
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
            res.matrix[i][j] = res.matrix[i][j] + matrix[i][k] * b.matrix[k][j];
          }
        }
      }
      return res;
    }

    void print(){
      for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
          // cout << matrix[i][j] << " ";
          printf("%4Lf ", matrix[i][j]);
        }
        cout << '\n';
      }
      cout << flush;
    }
};


int main(){
  Mat states(10);
  for(int i = 1; i <= 9; i++){
    states.matrix[i][i+1] = 1;
    if(i == 5){
      states.matrix[i][1] = 0.5;
    }
  }
  Mat nullmat(10);
  nullmat.identity();
  // states.print();
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    Mat res(10);
    Mat aux = states;
    res.identity();
    while(N > 0){
      if(N & 1){
        res = res * aux;
      }
      aux = aux * aux;
      N = N >> 1;
    }
    long double output = 0;
    for(int i = 1; i <= 20; i++){
      output += res.matrix[1][i];
    }
    cout << output << '\n';

  }

  return 0;
}
