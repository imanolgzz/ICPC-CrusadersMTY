#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        for(int j = 0; j < s.size();j++){
            if(!(j & 1)){
                if(s[j] == 'a'){
                    s[j] = 'b';
                }
                else{
                    s[j] = 'a';
                }
            }
            else {
                if(s[j] == 'z'){
                    s[j] = 'y';
                }
                else{
                    s[j] = 'z';
                } 
            }
        }
        cout << s << endl;
    }
    return 0;
}