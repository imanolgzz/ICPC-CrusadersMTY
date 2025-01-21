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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ (hash2 << 1); 
    } 
};

void solve(int iteration){
	ll n,x,y;
	cin >> n >> x >> y;
	unordered_map<pair<ll, ll>, ll, hash_pair> aux;
	ll res = 0;
	for(int i = 1; i <= n; i++){
		ll u,v,obj,ai;
		cin >> ai;
		u = ai % x;
		v = ai % y;
		obj = (x-u) % x;
		res += aux[{v,obj}];
		aux[{v,u}]++;
	}
	cout << res << ENDL;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
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