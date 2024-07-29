#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
 
    for(int i=0;i<t;i++){
        string num;
        cin>>num;
        int round = 0;
        vector<int> numbers;
        for(int j=0;j<num.size();j++){
            if(num[j] != '0'){
                round++;
                numbers.push_back((int)(num[j] - '0') * pow(10, (num.size() - 1)- j));
            }
        }
 
        cout << round << endl;
        for(int j = 0; j < numbers.size(); j++){
            cout << numbers[j] << " ";
        }
        cout << endl;
    }
    return 0;
}