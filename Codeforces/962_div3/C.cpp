#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
void printVec(vector<T> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << "\n";
}

template <typename T>
void printMat(vector<vector<T> > &mat){
  for(int i = 0; i < mat.size(); i++){
    cout << (char) (i + 97) << " - ";
    printVec(mat[i]);
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,q;
    cin >> n >> q;
    vector<vector<int> >letters1(26, vector<int>(n+1));
    vector<vector<int> >letters2(26, vector<int>(n+1));
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 1; i <= n; i++){
      letters1[(int)(str1[i-1]-'a')][i]++;
      letters2[(int)(str2[i-1]-'a')][i]++;
    }
    for(int i = 0; i < 26; i++){
      for(int j = 1; j <= n; j++){
        letters1[i][j] += letters1[i][j-1];
        letters2[i][j] += letters2[i][j-1];
      }
    }

    while(q--){
      int l,r;
      cin >> l >> r;
      int counter = 0;
      for(int i = 0; i < 26; i++){
        counter = counter + abs((letters2[i][r] - letters2[i][l-1]) - (letters1[i][r] - letters1[i][l-1]));
      }
      int output = ceil((float)counter / 2);
      cout << output << endl;
    }
  }
  return 0;
}