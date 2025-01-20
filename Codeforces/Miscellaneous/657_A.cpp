#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ENDL '\n'
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using namespace std;

void redirectIO();
template<class T> void print(vector<T> &vec);
template<class T> void print(vector<T> &vec, int start);
template<class T> void print(vector<vector<T>> &mat);
template<class T> void print(vector<vector<T>> &mat, int start);

// The solution starts here
bool isAbacaba(string &s, int start){
  string obj = "abacaba";
  for(int i = start; i <= start+6; i++){
    if(s[i] != obj[i-start]){
      return false;
    }
  }
  return true;
}

bool isAbac(string &s, int start){
  if(start < 0) return false;
  string obj = "abac";
  for(int i = start; i <= start + 3; i++){
    if(s[i] != obj[i-start]){
      return false;
    }
  }
  return true;
}

bool isCaba(string &s, int start){
  if(start + 3 >= s.size()) return false;
  string obj = "caba";
  for(int i = start; i <= start + 3; i++){
    if(s[i] != obj[i-start]){
      return false;
    }
  }
  return true;
}

bool isBacaba(string &s, int start){
  if(start + 5 >= s.size()) return false;
  string obj = "bacaba";
  for(int i = start; i <= start + 5; i++){
    if(s[i] != obj[i-start]){
      return false;
    }
  }
  return true;
}

bool isAbacab(string &s, int start){
  if(start < 0) return false;
  string obj = "abacab";
  for(int i = start; i <= start + 5; i++){
    if(s[i] != obj[i-start]){
      return false;
    }
  }
  return true;
}


bool canMakeAbacaba(string &s, int start){
  string obj = "abacaba";
  for(int i = start; i <= start+6; i++){
    if(s[i] != obj[i-start] && s[i] != '?'){
      return false;
    }
  }
  return true;
}

void solve(int iteration){
  string obj = "abacaba";
  int n;
  string s;
  cin >> n >> s;
  int counter = 0;
  for(int i = 0; i < n-6; i++){
    counter += isAbacaba(s, i);
  }

  if(counter >= 2){
    cout << "NO" << ENDL;
    return;
  }

  if(counter == 1){
    for(int i = 0; i < n; i++){
      if(s[i] == '?') s[i] = 'z';
    }
    cout << "YES" << ENDL;
    cout << s << ENDL;
    return;
  }
  bool flag = false;
  for(int i = 0; i < n-6; i++){
    if(canMakeAbacaba(s, i) && !isAbac(s, i-4) && !isCaba(s, i+7) && !isAbacab(s, i-6) && !isBacaba(s, i+7)){
      flag = true;
      for(int j = i; j <= i+6; j++){
        s[j] = obj[j-i];
      }
      break;
    } 
  }
  if(!flag){
    cout << "NO" << ENDL;
    return;
  }
  for(int i = 0; i < n; i++){
    if(s[i] == '?') s[i] = 'z';
  }

  cout << "YES" << ENDL;
  cout << s << ENDL;

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	redirectIO();
#endif

	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}

	return 0;
}

// Auxiliar methods not part of the solution

void redirectIO(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

template<class T>
void print(vector<T> &vec){
	for(int i = 0; i < vec.size(); ++i){
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

template<class T>
void print(vector<T> &vec, int start){
	for(int i = start; i < vec.size(); ++i){
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

template<class T>
void print(vector<vector<T>> &mat){
	for(int i = 0; i < mat.size(); ++i){
		print(mat[i]);
	}
}

template<class T>
void print(vector<vector<T>> &mat, int start){
	for(int i = start; i < mat.size(); ++i){
		print(mat[i], start);
	}
}