#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
int main(){
    long long k;
    long long number = 0;
    string n;
    cin >> k >> n;
    vector<long long>nums (10);
    for(int i = 0; i < n.size(); i++){
        number = number + ((int)n[i] - '0');
        // cout << ((int)n[i] - '0') << endl;
        nums[((int)n[i] - '0')]++;
    }
    if(number > k){
        cout << 0 << endl;
    } else {
        long long counter = 0, current = 0;
        while(number < k && current < 9){
            // cout << current << endl;
            if(nums[current] == 0){
                current++;
                continue;
            }
            number += (9 - current);
            nums[current] --;
            counter++;
        }
        cout << counter << endl;
    }
 
    return 0;
}
