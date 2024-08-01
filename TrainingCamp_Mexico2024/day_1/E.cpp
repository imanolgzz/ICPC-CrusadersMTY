#include <iostream>
using namespace std;

int main(){
  int a,b, p;
  string A, B, P;
  cin >> a >> b >> p >> A >> B >> P;
  int sum1, sum2, sum3;
  for(int i = 0; i < a; i++){
    sum1 = (sum1 + (int)(A[i] - '0')) % 9;
  }
  for(int i = 0; i < b; i++){
    sum2 = (sum2 + (int)(B[i] - '0')) % 9;
  }
  for(int i = 0; i < p; i++){
    if(P[i] != '*')
      sum3 = (sum3 + (int)(P[i] - '0')) % 9;
  }

  int output = ((sum1 * sum2) % 9) - sum3 % 9;
  if(output < 0){
    cout << 9 + output << endl;
  } else if(output == 0){
    cout << 9 << endl;
  } else {
    cout << output << endl;
  }

  return 0;
}