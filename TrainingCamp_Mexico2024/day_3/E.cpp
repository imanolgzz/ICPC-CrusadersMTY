#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
template <typename T>
void printVec(vector<T> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << endl;
}
 
int main(){
  int t;
  cin >>t;
  while(t--){
    int n,f,k;
    cin >> n >> f >> k;
    vector<int>numbers(n+1);
    for(int i = 1; i <=n; i++){
      int temp;
      cin >> temp;
      numbers[i] = temp;
    }
    int favorite = numbers[f];
    numbers.push_back(10000);
    sort(numbers.begin(), numbers.end(), greater<int>());
    //printVec(numbers);
    if(numbers[k] > favorite){
      cout << "NO" << endl;
    } else if(numbers[k] < favorite){
      cout << "YES" << endl;
    } else {
      if(numbers[k+1] == favorite){
        cout << "MAYBE" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}