#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> divisores;
    for(int i = 1; (long long)i * i <= n; i++){
        if(n % i == 0){
            divisores.push_back(i);
            if((long long)i * i != n) divisores.push_back(n/i);
            // cout << i << " " << n/i << " ";
        }
    }
    if(k > divisores.size()){
        cout << -1 << endl;
        return 0;
    }
    if(divisores.size() & 1){
        if(k > divisores.size()/2 + 1){
            cout << divisores[divisores.size() - 2 - (2 * (k - (divisores.size()/2 + 2)))] << endl;
        } else {
            cout << divisores[2 * (k-1)] << endl;
        }
    } else {
        if(k > divisores.size() / 2){
            cout << divisores[divisores.size() - 1 - (2 * (k - (divisores.size()/2 + 1)))] << endl;
        } else {
            cout << divisores[2 * (k-1)] << endl;
        }
    }
 
    return 0;
}