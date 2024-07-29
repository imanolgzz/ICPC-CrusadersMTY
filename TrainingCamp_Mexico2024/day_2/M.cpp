#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main(){
    unordered_map <char, int> letters;
    vector<int> indexes;
    int k;
    string q;
    cin >> k >> q;
 
    for(int i = 0; i < q.size(); i++){
        if(letters.find(q[i]) == letters.end()){
            letters[q[i]] = i;
        }
    }
    for(auto letter: letters){
        indexes.push_back(letter.second);
    }
    sort(indexes.begin(), indexes.end());
    if(indexes.size() < k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
 
    for(int i = 0; i < k-1; i++){
        cout << q.substr(indexes[i], indexes[i+1] - indexes[i]) << endl;
    }
 
    cout << q.substr(indexes[k-1], q.size() - indexes[k - 1]) << endl;
    return 0;
}