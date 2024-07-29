#include <iostream>
#include <vector>

using namespace std;

long long counter = 0;

void swap(vector<long long> &vector, long long i, long long j){
  counter++; 
  long long temp = vector[i];
  vector[i] = vector[j];
  vector[j] = temp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<vector<long long> >correct(2, vector<long long>(n+1));
  vector<vector<long long> >shoes (2, vector<long long>(n+1));
  for(int it = 0; it <= 1; it++){
    for(long long i = 1; i <= n; i++){
      long long temp;
      cin >> temp;
      shoes[it][i] = temp;
      correct[it][temp] = i;
    }
  }
  for(int it = 0; it <= 1; it++){
    for(long long i = 1; i <= n; i++){
      long long actual = shoes[it][i];
      if(actual != i){
        long long correctPosition = correct[it][i];
        swap(shoes[it], i, correctPosition);
        correct[it][actual] = correctPosition;
      }
    }
  }
  std::cout << counter << "\n";

  return 0;
}