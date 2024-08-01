#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int N, K, L;
  cin >> N >> K >> L;
  int answer = ceil((float)N * K / L);
  cout << answer << endl;
  return 0;
}