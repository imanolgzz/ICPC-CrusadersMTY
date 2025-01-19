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
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll currentCans = 0;
	ll level = 0;
	ll movements = 0;
	ll i = 0;

	while(currentCans < k){
		if(a[i] > level){
			ll secure = (n-i) * (a[i] - level);
			if(currentCans + secure >= k){
				movements += k - currentCans;
				currentCans += secure;
			} else {
				currentCans += secure;
				movements += secure;
				level = a[i];
			}
		} else {
			movements++;
			i++;
		}
	}
	cout << movements << endl;

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