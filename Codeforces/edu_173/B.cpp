#include <bits/stdc++.h>

using namespace std;

void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // redirectIO();
  int t;
  cin >> t;
  while(t--){
    int n, d;
    cin >> n >> d;
    cout << 1 << ' ';
    // Si la cantidad de dígitos es múltiplo de 3 o el número es un 3 entonces el 3 pasa
    if(d == 3 || d == 6 || d == 9 || n >= 3){
      cout << 3 << ' ';
    }

    // Si el número es un 5 entonces esl 5 pasa
    if(d == 5){
      cout << 5 << ' ';
    }
    
    // Si la cantidad de dígitos es múltiplo de 3 y de 2 o el número es un 7 entonces el 7 pasa
    if(d == 7 || n >= 3){
      cout << 7 << ' ';
    }

    // Si la cantidad de dígitos es múltiplio de 9 o el número es un 9 entonces el 9 pasa
    if(d == 9 || (d == 6 && n >= 3) || (d == 3 && n >= 3) || n >= 6){
      cout << 9 << ' '; 
    }
    cout << endl;
  }
  return 0;
}