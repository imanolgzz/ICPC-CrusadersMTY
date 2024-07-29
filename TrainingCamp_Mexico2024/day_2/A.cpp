#include <iostream>
using namespace std;
 
int main(){
    int n,a,b;
    string airports;
    cin >> n >> a >> b >> airports;
    int left = a, right= a;
 
    if (airports[a-1]== airports[b-1]){
        cout << 0 << endl;
        return 0;
    } else {
        cout << 1 << endl;
    }
 
 
    return 0;
}