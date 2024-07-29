#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main(){
    int n, a, b, c, x, y, z;
    cin >> n;
    vector<int> output;
    cout << "? 1 2" << endl;
    fflush(stdout); cin >> x;
    cout << "? 2 3" << endl;
    fflush(stdout); cin >> y;
    cout << "? 1 3" << endl;
    fflush(stdout); cin >> z;
    a = (x - y + z) / 2;
    c = z - a;
    b = y - c;
    output.push_back(a);
    output.push_back(b);
    output.push_back(c);
 
    for(int i = 1; i < n - 2; i++){
        int temp;
        string query = "? 1 ";
        query = query + to_string(i + 3);
        cout << query << endl;
        fflush(stdout); cin >> temp;
        output.push_back(temp - a);
    }
 
    cout << "! ";
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
 
    cout << endl;
 
    return 0;
}