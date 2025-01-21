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
const ll mod = 998244353;

const ll MAXN = 3e5; 
vector<ll> fact(MAXN), invFact(MAXN);

inline ll modF(ll i) {
    return (i % mod + mod) % mod;
}

ll modExp(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precomputeFactorials(int maxN) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[maxN] = modExp(fact[maxN], mod - 2, mod);
    for (int i = maxN - 1; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

ll divideFactorials(int n, int k) {
    if (k > n) return 0;
    return fact[n] * invFact[k] % mod;
}

void solve(int iteration){
	ll n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll maxNum = *(a.end()-1);
	ll secondMax = *(a.end()-2);
	ll maxCount = 0;
	ll secondMaxCount = 0;
	for(int i = 1; i <= n; i++){
		maxCount += a[i] == maxNum;
		secondMaxCount += a[i] == secondMax;
	}
	if(maxNum - secondMax >= 2 && maxCount == 1){
		cout << 0 << ENDL;
		return;
	}	

	ll res;
	res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
		res %= mod;
	}	

	if(!(maxNum - secondMax == 0 || maxCount >= 2)){
		for(ll i = secondMaxCount + 1; i <= n; i++){
			ll leftNums = i-1;
			ll rightNums = n-i;
			ll numsToChoose = n - secondMaxCount - 1;
			res = res - modF(fact[leftNums]*divideFactorials(numsToChoose, leftNums - secondMaxCount));
		}
	}
	cout << res << ENDL;

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	redirectIO();
#endif
	precomputeFactorials(MAXN);
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