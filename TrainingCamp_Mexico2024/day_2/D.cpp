#include <iostream>
#include <math.h>
 
using namespace std;
 
int main(){
    int n, output;
    long long left, right, k;
    cin >> n >> k;
    left = 1;
    right = (long long) pow(2,n + 1) - 1;
    output = n + 1;
    while(left <= right){
        long long mid = (left + right) / (long long)2;
        if(mid == k){
            cout << output << endl;
            return 0;
        }
        if(mid > k){
            right = mid - 1;
            output--;
            continue;
        }
 
        if(mid < k){
            left = mid + 1;
            output--;
            continue;
        }
    }
 
    cout << output << endl;
 
    return 0;
}