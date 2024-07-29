#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int L,W,H, l,w,h;
  cin >> l >> w >> h >> L >> W >> H;
  int a = (l / L) * (w / W) * (h / H);
  int b = (l / L) * (w / H) * (h / W);
  int c = (l / H) * (w / L) * (h / W);
  int d = (l / H) * (w / W) * (h / L);
  int e = (l / W) * (w / H) * (h / L);
  int f = (l / W) * (w / L) * (h / H);
  cout << max(max(a,max(b,c)), max(d, max(e,f))) << endl;
  return 0;
}