#include <iostream>
#include <unordered_map>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int l=0;
    int r=s.length()-1;
 
    int diff=0;
    
    while(l<r && diff<2){
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            diff++;
            l++;
            r--;
        }
    }
 
    if(diff > 1 || (diff == 0 && !(s.length() & 1))){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    
    return 0;
}