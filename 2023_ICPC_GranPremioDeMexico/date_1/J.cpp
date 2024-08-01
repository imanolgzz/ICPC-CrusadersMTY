//unsolved
#include <iostream>
#include <vector>

using namespace std;

int const mod = 1e9+7;

/*

1 2 3 4 5 6 7 8 9 10

*/

template <typename T>
void printVec(vector<T> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << '\n';
}

template <typename T>
void printMat(vector<vector<T> > &mat){
  for(int i = 0; i < mat.size(); i++){
    printVec(mat[i]);
  }
}

long long jumpingEnergy(vector<long long> &energies, vector<vector<long long> > &memo, int l, int r){
  if(l == (r-1)){
    long long res = ((long long)energies[r] * energies[l]) % mod;
    return res;
  } else if(r == l){
    return energies[r]; 
  }
  if(memo[l][r] != -1){
    return memo[l][r];
  }
  long long c1 = jumpingEnergy(energies, memo, l+1, r);
  long long c2 = jumpingEnergy(energies, memo, l, r-1);
  long long c3 = energies[r] * energies[l];
  long long c4;
  if((r - l) == 2){
    c4 = 0;
  } else {
    c4 = jumpingEnergy(energies, memo, l+1, r-1);
  } 
  long long res = (c1 + c2 + c3 - c4)% mod;
  memo[l][r] = res;
  return memo[l][r];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N,Q;
  cin >> N >> Q;
  vector<long long> energies(N+1);
  vector<vector<long long> > memo (N+1, vector<long long>(N+1, -1));
  for(int i = 1; i <= N; i++){
    cin >> energies[i];
  }
  while(Q--){
    int L, R;
    cin >> L >> R;
    cout << jumpingEnergy(energies, memo, L, R) << "\n";
  }
  // printMat(memo);

}