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
    long long n;
    cin >> n;
    if (n < 10) { 
        cout << n + 1 << endl;
        return 0;
    }
    long long digits = 0;
    long long temp = n;
    string auxStr = "";
    while(temp > 0){
        digits++;
        temp = temp / 10;
        auxStr += '1';
    }

    long long auxNum = stoll(auxStr);

    long long output =digits * 10;
    long long number = 9 * auxNum;

    while(number > n){
        number = number - auxNum;
        output--;
    }
    output--;
    cout << output << endl;


    return 0;
}