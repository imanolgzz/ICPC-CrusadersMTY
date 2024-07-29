#include <iostream>
 
using namespace std;
 
int main(){
    int coins, x, y;
    cin >> coins;
    for(int i = 0; i < coins; i++){
        cin >> x >> y;
        if(y >= -1){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}