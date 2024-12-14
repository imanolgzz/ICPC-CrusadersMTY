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

char toLowerCase(char letter){
    return (char)((int)letter - 'A' + 'a');
}

void getPossibleCombinations(int i, string &word, vector<string> &combinations, string current){
    int last = word.size() - 1;
    if(i > last + 1){
        return;
    } else if(i == last + 1) {
        combinations.push_back(current);
    } else if(i == last){
        combinations.push_back(current + 's');
    } else {
        getPossibleCombinations(i + 1, word, combinations, current + 's');
        getPossibleCombinations(i + 2, word, combinations, current + 'B');
    }
}

int main(){
    // setIO();
    string s;
    cin >> s;
    int counter = 0;
    vector<pair<string, bool> > words;
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'S'){
            if(counter == 1){
                temp += 's';
            } else if(counter > 1){
                words.push_back(pair<string, bool>(temp, true));
                temp = "";
            }
            counter = 0;
            temp += toLowerCase(s[i]);
        } else {
            if(counter > 0){
                if(counter == 1){
                    words.push_back(pair<string,bool>(temp, false));
                    temp = "ss";
                    counter = 2;
                } else {
                    counter ++;
                    temp += 's';
                }
            } else {
                counter++;
            }
        }
    }
    if(counter > 1){
        words.push_back(pair<string, bool>(temp, true));
    } else if (counter == 1) {
        words.push_back(pair<string, bool>(temp + 's', false));
    } else {
        words.push_back(pair<string,bool>(temp, false));
    }

    vector<vector<string> > combinations(words.size(), vector<string>());

    for(int i = 0; i < words.size(); i++){
        if(words[i].second){
            getPossibleCombinations(0, words[i].first, combinations[i], "");
        } else {
            combinations[i].push_back(words[i].first);
        }
    }
    vector<string> output = combinations[0];

    for(int i = 1; i < combinations.size(); i++){
        vector<string> temp;
        for(int j = 0; j < combinations[i].size(); j++){
            for(int k = 0; k < output.size(); k++){
                temp.push_back(output[k] + combinations[i][j]);
            }
        }
        output = temp;
    }

    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }
    return 0;
}