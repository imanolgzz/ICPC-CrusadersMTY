// unsolved
#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n >= 1 && n < 10){
      // a - b is the amount of time that a digit is going to repeat itself
      // we start to search for two numbers (a,b) that satisfy a - b = 1 and n * a - b = 2
      // after that we continue with one more digit a - b = 2 and n * a - b = 22
      // then a - b = 3 and n * a - b = 222 and so on until we get to the limit of a and b
      // we generalize and obtain (n - 1) * a = "2"*i - i | b = a - i
      int strLength = 2;
      int init = 11;
      int a = 1, b = 1;
      string output = "";
      int counter = 0;
      while(a <= 10000){
        int objective = n * init;
        int numerator = objective - strLength;
        int denominator = n - 1;
        a = numerator / denominator;
        b = a - strLength;
        if(numerator % denominator == 0 && b <= min(10000, a * n)){
          counter++;
          output = output + to_string(a) + ' ' + to_string(b) + '\n';
        }
        strLength++;
        init = init * 10 + 1;
      }
      cout << counter << '\n' << output;
    } else if(n >= 10 && n < 100){
      int strLength = 4;
      int init = 101;
      int a = 1, b = 1;
      string output = "";
      int counter = 0;
      while(a <= 10000){
        // 2 * a - b = i, n * a - b = objective
        // (n - 2) * a = objective - i  
        // i = 1005
        int objective = n * init;
        int numerator = objective - strLength;
        int denominator = n - 2;
        a = numerator / denominator;
        b = 2 * a - strLength;
        cout << a << " " << b << endl;
        if(numerator % denominator == 0 && b <= min(10000, a * n)){
          counter++;
          output = output + to_string(a) + ' ' + to_string(b) + '\n';
        }
        strLength+=2;
        init = init * 100 + 1;
      }
      cout << counter << '\n' << output;
    } else {

    }
  }
  return 0;
}