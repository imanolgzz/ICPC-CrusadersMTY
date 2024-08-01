#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long counter = 0; 

int otherPlayer(int turn){
  if(turn == 1){
    return 2;
  } else {
    return 1;
  }
}

int winner(vector<vector<vector<int> > > &memo, int turn, int possible, int remain){
  if(remain <= possible){
    // if I can take al the remaining chips I win
    return turn;
  }

  if(memo[possible][remain][turn] != 0){
    // if I already calculate this case, return it
    return memo[possible][remain][turn];
  }

  counter++;

  bool winning = false;
  for(int i = 1; i <= possible; i++){
    // calculate every gaming scenario (theorically there are at most 5 * 10 ^ 7). 
    // If I win in any of them then If I play optimally from now I will win
    // otherwise it is deterministic that I will lose
    int caseW = winner(memo, otherPlayer(turn), possible + 1, remain - i);
    if(caseW == turn){
      winning = true;
      break;
    }
  }
  if(winning){
    memo[possible][remain][turn] = turn;
  } else {
    memo[possible][remain][turn] = otherPlayer(turn);
  }

  return memo[possible][remain][turn];

}

int main(){
  int N;
  cin >> N;
  vector<vector<vector<int> > >memo(N+1, vector<vector<int> >(N+1, vector<int>(2)));
  int who = winner(memo, 1, 1, N);
  if(who == 1){
    cout << "Jane" << endl;
  } else if (who == 2){
    cout << "John" << endl;
  } else {
    cout << "error" << endl;
  }
  cout << counter << endl;
  /*
  1
  2 
  3
  4
  5
  6
  7
  8
  N^2 + N / 2 > 6 // 2
  
  */
  return 0;
}