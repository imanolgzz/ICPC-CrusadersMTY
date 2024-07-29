#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int main(){
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> s;
        int counter = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'U'){
                counter++;
            }
        }
        if(counter & 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}