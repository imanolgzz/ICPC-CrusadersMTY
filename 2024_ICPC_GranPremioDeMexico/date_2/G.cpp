// unsolved
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
int maxTraffic = 0;
int edges = 0;
template <typename T>
void printVec(vector<T> &vec){
  for(T item : vec){
    cout << item << " ";
  }
  cout << '\n';
}

template <typename T>
void printMat(vector<vector<T> > &mat){
  for(int i = 0; i < mat.size(); i++){
    cout << i << " - "; printVec(mat[i]);
  }
}

int getChilds(vector<vector<int> > &forest, vector<int> &memo, int node, int parent){
  if(memo[node] != -1){
    return memo[node];
  }

  if(forest[node].size() == 1 && forest[node][0] == parent){
    memo[node] = 0;
    return memo[node];
  }

  int childs = 0;
  for(int i = 0; i < forest[node].size(); i++){
    if(forest[node][i] != parent){
      childs = childs + getChilds(forest, memo, forest[node][i], node) + 1;
    }
  }
  memo[node] = childs;
  return memo[node];
}

void dfsLength(vector<vector<int> > &forest, vector<int> &memo, int node, int parent){
  for(int i = 0; i < forest[node].size(); i++){
    if(forest[node][i] != parent){
      int rElements = memo[forest[node][i]] + 1;
      int lElements = n - rElements;
      int traffic = rElements * lElements;
      if(traffic > maxTraffic){
        edges = 1;
        maxTraffic = traffic;
      } else if(traffic == maxTraffic){
        edges++;
      }
      dfsLength(forest, memo, forest[node][i], node);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   cin >> n;
  vector<vector<int> > forest(n+1, vector<int>());
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    forest[u].push_back(v);
    forest[v].push_back(u);
  }
  int root = 1;
  vector<int> memo(n+1, -1);
  memo[0] = 0;
  int rootChilds = getChilds(forest, memo, root, 0);

  /*
  unordered_set<int> visited;
  for(int i = 1; i <= n; i++){
    for(int item : forest[i]){
      if(visited.find(item) != visited.end()) continue;
      int rElements = memo[item] + 1;
      int lElements = n - rElements;
      int traffic = rElements * lElements;
      if(traffic > greater){
        edges = 1;
        greater = traffic;
      } else if(traffic == greater){
        edges++;
      }
    }
    visited.insert(i);
  }
  */
  dfsLength(forest, memo, 1, 0);
  cout << maxTraffic << ' ' << edges << '\n'; 
  return 0;
}