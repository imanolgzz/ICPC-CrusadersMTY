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

ll getSum(vector<vector<ll>> &adjList, vector<ll> &a, ll node, ll parent, bool take){
	ll res = 0;
	for(ll &child : adjList[node]){
		if(child == parent) continue;
		res += getSum(adjList, a, child, node, !take);
	}

	if(take){
		res += a[node];
	}
	return res;
}

void solve(int iteration){
  int n;
  cin >> n;
	ll totalSum = 0;
  vector<ll> a(n+1);
	vector<vector<ll>> adjList(n+1, vector<ll>());
  for(ll i = 1; i <= n; i++){
    cin >> a[i];
		totalSum += a[i];
  }

	for(ll i = 1; i <= n-1; i++){
		ll u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	ll partialSum = getSum(adjList, a, 1, -1, true);
	vector<ll> tmp = {totalSum, partialSum, totalSum - partialSum};
	sort(tmp.begin(), tmp.end());
	cout << tmp[0] + tmp[2] << ENDL;
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