#include <iostream>
 
using namespace std;
 
int main(){
    int n, impares = 0;
    cin >> n;
    for(int i = 0; i < n;  i++){
        int temp;
        cin >> temp;
        if(temp & 1) impares++; 
    }
    if(impares < n - impares){
        cout << impares << endl;
    } else {
        cout << n - impares << endl;
    }
    return 0;
}
