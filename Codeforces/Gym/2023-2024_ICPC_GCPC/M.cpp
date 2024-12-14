#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <climits>

using namespace std;

void setIO(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

int main(){
    // setIO();
    int d;
    cin >> d;
    if(d > 9){
        cout << "1 2 3" << endl;
    } else {
        cout << "97 79 51" << endl;
    }
    return 0;
}
