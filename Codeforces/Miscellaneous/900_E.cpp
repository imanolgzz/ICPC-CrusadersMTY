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
	vector<int> a(n+1);
	vector<vector<int>> bitDp(32, vector<int>(n+2));

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = n; i >= 1; i--){
		int num = a[i];
		for(int j = 0; j < 32; j++){
			if(num & 1){
				bitDp[j][i] = bitDp[j][i+1]+1;
			}
			num = num >> 1;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int l, k;
		cin >> l >> k;
		int length = 1e9+7;
		int tope = 0;
		int mostSignificant = -1;
		for(int i = 31; i >= 0; i--){
			if((k >> i) & 1){
				if(mostSignificant == -1){
					mostSignificant = i;
				}
				length = min(length, bitDp[i][l]);
			} else if(bitDp[i][l] > 0 && mostSignificant != -1){
				tope = max(tope, min(bitDp[i][l], length));
			}	
		}
		for(int i = mostSignificant+1; i <= 31; i++){
			length = max(length, bitDp[i][l]);
		}
		length = max(length, tope);
		if(length == 0){
			cout << -1 << ' '; 
		} else {
			cout << l + length - 1 << ' ';
		}
	}
	cout << ENDL;
	
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