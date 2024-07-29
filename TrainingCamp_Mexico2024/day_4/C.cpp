#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(int w = 0; w < t ; w++){
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for(int j = 0; j < n; j++){
            string item;
            cin >> item;
            matrix[j] = item;
        }
        if(m < 4){
            cout << "NO" << endl;
            continue;
        }
        int leftP = 0, rightP = matrix[0].size() - 1;
        bool v,i,k,a;
        v = i = k = a = false;
        bool flag = false;
        while(leftP < rightP && (!v || !i || !k || !a)){
            for(int j = 0; j < n; j++){
                if(!v){
                    if(matrix[j][leftP] == 'v'){
                        v = true;
                        break;
                    }
                } else if(!i){
                    if(matrix[j][leftP] == 'i'){
                        i = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            if(!v || !i){
                leftP++;
            }
            for(int j = 0; j < n; j++){
                if(!a){
                    if(matrix[j][rightP] == 'a'){
                        a = true;
                        break;
                    }
                } else if(!k){
                    if(matrix[j][rightP] == 'k'){
                        k = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            if(!a || !k){
                rightP--;
            }
        }
        if(v && i && k && a){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}