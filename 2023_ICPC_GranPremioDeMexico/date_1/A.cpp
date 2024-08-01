#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  int N;
  cin >> N;
  unordered_set<string>unique;
  unordered_set<string>repeated;
  while(N--){
    int X;
    cin >> X;
    string alias = ""; 
    while(X--){
      string name;
      cin >> name;
      alias += name[0];
    }
    if(repeated.find(alias) == repeated.end()){
      unique.insert(alias);
      repeated.insert(alias);
    } else {
      unique.erase(alias);
    }
  }
  cout << unique.size() << endl;
}