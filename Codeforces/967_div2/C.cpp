#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<pair<int,int> > edgeList;
    vector<vector<int> > adjMatrix(n+1, vector<int>(n+1));
    unordered_set<int> numbers;

    for(int i = 1; i <= n; i++){
      int objective = 0;
      int answer = 1;
      if(i == 1) answer = 2;
      while(answer != i){
        objective = answer;
        cout << "? " << i << " " << objective << endl;
        cin >> answer;
      }
      adjMatrix[i][objective] = 1;
      adjMatrix[objective][i] = 1;
      edgeList.push_back(pair<int,int>(i, objective));
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
      for(int j = i+1; j <= n; j++){
        if(adjMatrix[i][j] == 1){
          cout << i << " " << j << " ";
        }
      }
    }
    cout << endl;
    /*
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
    }
    for(int i = 0; i < edgeList.size(); i++){
      cout << edgeList[i].first << " " << edgeList[i].second << " ";
    }
    */
    cout << endl;
  }

  return 0;
}