#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <climits>
#include <stack>
#include <unordered_map>
using namespace std;

void setIO(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO();
    string s;
    cin >> s;
    unordered_map <string, int> uniqueWords;
    int counter = 0;
    for(int i = 0; i < s.size();){
        int wordStart = i;
        string temp = "";
        counter = 0;
        do {
            temp+= s[i];
            if(s[i] == '('){
                counter++;
            } else {
                counter--;
            }
            // cout << counter  << ' ' << s[i]<< endl;
            i++;
        } while(counter > 0 && i < s.size());
        uniqueWords[temp] = wordStart; 
    }
    if(uniqueWords.size() >= 2){
        int start = 0;
        bool flag = false;
        for(auto item: uniqueWords){
            if(item.second != 0){
                start = item.second;
                break;
            } 
        }
        string output = "";
        for(int i = start; i < s.size(); i++){
            output += s[i];
        }
        for(int i = 0; i < start; i++){
            output += s[i];
        }
        cout << output << endl;
    } else {
        cout << "no" << endl;
    }


    return 0;
}
