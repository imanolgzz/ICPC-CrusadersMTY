#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int a,b,c;
    cin >> a >> b >> c;
    int counter = 5;
    while(counter--){
      int minVal = min(a,min(b,c));
      if(minVal == a){
        a++;
      } else if(minVal == b){
        b++;
      } else{
        c++;
      }
    }
    cout << a * b * c << endl;;
  }
}