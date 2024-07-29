#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vector<int> aux;
        aux.push_back(a);
        aux.push_back(b);
        aux.push_back(c);
        sort(aux.begin(), aux.end());
        cout << aux[1] << endl;
    }
 
    return 0;
}