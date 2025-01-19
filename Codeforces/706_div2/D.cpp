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

void solve(int iteration){
	int n;
	cin >> n;
	vector<int> p(n+2);
	vector<int> leftStairs(n+1);
	vector<int> rightStairs(n+1);
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	for(int i = 2; i <= n; i++){
		if(p[i] > p[i-1]){
			leftStairs[i] = leftStairs[i-1] + 1;
		} else {
			leftStairs[i] = 0;
		}
	}

	for(int i = n - 1; i >= 1; i--){
		if(p[i] > p[i+1]){
			rightStairs[i] = rightStairs[i+1]+1;
		} else {
			rightStairs[i] = 0;
		}
	}

	int maxNum = 0;
	int maxCount = 0;
	int index = -1;
	for(int i = 1; i <= n; i++){
		int maxTmp = max(rightStairs[i], leftStairs[i]);
		maxNum = max(maxTmp, maxNum);
	}

	for(int i = 1; i <= n; i++){
		int maxTmp = max(rightStairs[i], leftStairs[i]);
		if(maxTmp == maxNum){
			maxCount++;
			index = i;
		}	
	}

	if(maxCount >= 2 || rightStairs[index] == 0 || leftStairs[index] == 0){
		cout << 0 << endl;
		return;
	}

	int res = 0;
	vector<int> tmp = {rightStairs[index], leftStairs[index]};
	sort(tmp.begin(), tmp.end());
	if(!(tmp[1] & 1)){
		tmp[1]--;
	}
	if(tmp[0] > tmp[1]){
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	redirectIO();
#endif

	int t = 1;
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