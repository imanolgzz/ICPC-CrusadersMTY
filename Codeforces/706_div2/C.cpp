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
	vector<int> miners(n);
	vector<int> diamonds(n);
	int m = 0, d = 0;
	for(int i = 1; i <= 2 * n; i++){
		int x, y;
		cin >> x >> y;
		if(y == 0){
			// there is a diamond
			diamonds[d] = abs(x);
			d++;
		} else {
			miners[m] = abs(y);
			m++;
		}
	}
	sort(miners.begin(), miners.end());
	sort(diamonds.begin(), diamonds.end());
	ld res = 0;	
	for(int i = 0; i < n; i++){
		res += sqrt((ld)((ll)miners[i]*miners[i] + (ll)diamonds[i]*diamonds[i]));
	}
	cout.precision(100);
	cout << res << ENDL;
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