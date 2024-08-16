#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void setIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
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
    long long xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    long double m, b;
    long double numerator = yt - ys, denominator = xt - xs;
    long double A, B, C; 
    if(numerator != 0 && denominator != 0){
      b = ys - m * xs;
      A = -m;
      B = 1;
      C = -b;
    } else if (numerator == 0){
      // y = yt
      // 0x + 1y - yt = 0;
      A = 0;
      B = 1;
      C = - yt;
    } else {
      A = 1;
      B = 0;
      C = -xt; 
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
      // cout << A << " " << B << " " << C << endl;
      long double xi = circles[i].first, yi = circles[i].second;
      // cout << xi << " " << yi << endl;
      // cout << abs(A * xi + B * yi + C) << " " << sqrt(A * A + B * B)<< endl;
      long double distance = abs(A * xi + B * yi + C)/sqrt(A * A + B * B);
      // cout << distance << " ";
      long double xObj, yObj;
      xObj = (B * (B * xi - A * yi) - A * C)/(A * A + B * B);
      yObj = (A * (-B * xi + A * yi) - B * C)/(A * A + B * B);
      //  calculate distance between origin and circle;
      long double pathDistance = sqrt(pow((xs - xObj), 2) + pow(ys - yObj, 2));
      cout << "x path: " << xObj << "  y path: " << yObj << endl;
      cout << "x origin: " << xs << "  y origin: " << ys << endl;
      cout << "x circle: " << xi << "  y circle: " << yi << endl;
      cout << distance << " " << pathDistance << endl;
      if(distance > pathDistance){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
    /*
    The formula for the distance between a point and a line is
    d = abs(a * x0 + b * y0 + c) / sqrt(a * a + b * b)
    where the line is ax + by + c = 0

    */

  }
  return 0;
}