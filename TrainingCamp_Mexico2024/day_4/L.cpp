#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
int main(){
    int n,k,q;
    int leftIt = 200004, rightIt = -1;
    cin >> n >> k >> q;
    vector<int> recommended(200000+5);
    vector<int> acceptable(200000+5);
    for(int it = 0; it < n; it++){
        int l, r;
        cin >> l >> r;
        leftIt = min(leftIt, l);
        rightIt = max(rightIt, r);
        recommended[l]++; recommended[r+1]--;
    }
 
    int temp = leftIt;
 
    while(leftIt <= rightIt){
        recommended[leftIt] = recommended[leftIt] + recommended[leftIt-1];
        if(recommended[leftIt] >= k){
            acceptable[leftIt]++;
        }
        leftIt++;
    }
 
    leftIt = 0;
    rightIt = 200003;
 
    while(leftIt <= rightIt){
        acceptable[leftIt] = acceptable[leftIt] + acceptable[leftIt-1];
        leftIt++;
    }
 
    for(int it = 0; it < q; it++){
        int a,b;
        cin >> a >> b;
        int answer = acceptable[b] - acceptable[a-1];
        cout << answer << endl;
    }
 
    return 0;
}