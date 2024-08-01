#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int output = 0;
  int aux;
  if(n >= 100){
    output += n / 100;
    n = n % 100;

  }
  if(n >= 20){
    output += n / 20;
    n = n % 20;
  }
  if(n >= 10){
    output += n / 10;
    n = n % 10;
  }
  if(n >= 5){

    output += n / 5;
    n = n % 5;
  }
  if(n >= 1){
    output += n / 1;
    n = n % 1;
  }
  cout << output << endl;
  return 0;
}