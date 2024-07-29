#include <iostream>
#include <unordered_set>
 
using namespace std;
 
int main(){
    int a,b,c,d, objective, test = 0;
    int x = 0, y = 0;
    unordered_set<int> results;
    cin >> a >> b >> c >> d;
    objective = d - b;
    // a * x - c * y = d - b
    // a * x - c * y = objective
 
    while(results.find(test) == results.end()){
        if(test == objective){
            cout << x * a + b << endl;
            return 0;
        } else if (test > objective) {
            y++;
        } else {
            x++;
        }
        results.insert(test);
        test = a * x - c * y;
    }
 
    cout << -1 << endl;
 
    return 0;
}