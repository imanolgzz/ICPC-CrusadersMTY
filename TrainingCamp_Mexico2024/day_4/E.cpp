#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        long long n;
        cin >> n;
        long long first = n / 2;
        long long output = n - first + 1;
        cout << output << endl;
    }
    return 0;
}