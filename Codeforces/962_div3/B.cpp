#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    int rows = 0, columns = 0;
    cin >> n >> k;
    vector<string> matrix(n);
    for(int i = 0; i < n; i++){
      cin >> matrix[i];
    }

    for(int i = 0; i < n; i+= k){
      for(int j = 0; j < n; j+= k){
        cout << matrix[i][j];
      }
      cout << '\n';
    }
  }
}