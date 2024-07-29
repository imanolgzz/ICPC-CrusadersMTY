#include <iostream>
#include <math.h>
 
using namespace std;
 
int main(){
    int n, h, counter = 0;
    long double eachArea, previousArea = 0;
    cin >> n >> h;
    eachArea = (long double)h / (2 * n);
    cout << fixed;
    while(counter < n - 1){
        previousArea = eachArea * counter;
        long double newHeight = sqrt((eachArea + previousArea) * 2 * h);
        cout << newHeight << " ";
        counter++;
    }
 
    return 0;
}