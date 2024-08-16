#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

long double euclideanDistance(long double xi, long double xo, long double yi, long double yo){
  long double distance = sqrt((xo - xi) * (xo - xi) + (yo - yi) * (yo - yi));
  return distance;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  setIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<pair<long long, long long> > circles(n + 1, pair<long long,long long>());
    for(int i = 1; i <= n; i++){
      cin >> circles[i].first;
      cin >> circles[i].second;
    }
    long double xs, ys, xt, yt;
    bool flag = true;
    cin >> xs >> ys >> xt >> yt;
    long double distanceToObjective = euclideanDistance(xs, xt, ys, yt);
    // cout << t << " " << distanceToObjective << ' ';
    for(int i = 1; i <= n; i++){
      long double distanceToObjectiveCircle = euclideanDistance(circles[i].first, xt, circles[i].second,yt);
      // cout << distanceToObjectiveCircle << ' ';
      if(distanceToObjectiveCircle <= distanceToObjective){
        flag = false;
        break;
      }
    }
    // cout << endl;
    if(flag){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}