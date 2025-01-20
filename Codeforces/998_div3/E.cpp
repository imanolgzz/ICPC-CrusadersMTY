#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ENDL '\n'
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;

void redirectIO();
template<class T> void print(vector<T> &vec);
template<class T> void print(vector<T> &vec, int start);
template<class T> void print(vector<vector<T>> &mat);
template<class T> void print(vector<vector<T>> &mat, int start);

// The solution starts here

void dfs(int node, vector<unordered_set<int>> &sets, vector<int> &setNum, vector<vector<int>> &adjListG, int &currentSet){
	if(setNum[node] != -1) return;
	if(currentSet == sets.size()){
		sets.push_back(unordered_set<int>());
	}
	setNum[node] = currentSet;
	sets[currentSet].insert(node);
	for(int &child : adjListG[node]){
		dfs(child, sets, setNum, adjListG, currentSet);
	}
}

void solve(int iteration){
	int n, m1 , m2;
	cin >> n >> m1 >> m2;
	int res = 0;
	vector<pair<int,int>> originalF(m1+1, pair<int,int>());
	vector<vector<int>> adjListG(n+1, vector<int>());
	vector<vector<int>> adjListF(n+1, vector<int>());
	vector<unordered_set<int>> sets;
	vector<unordered_set<int>> setsF;
	vector<int> setNum(n+1, -1);
	vector<int> setNumF(n+1, -1);
	for(int i = 1; i <= m1; i++){
		cin >> originalF[i].first;
		cin >> originalF[i].second;
	}
	for(int i = 1; i <= m2; i++){
		int u, v;
		cin >> u >> v;
		adjListG[u].pb(v);
		adjListG[v].pb(u);
	}
	int currentSet = -1;
	for(int i = 1; i <= n; i++){
		if(setNum[i] == -1) currentSet++;
		dfs(i, sets, setNum, adjListG, currentSet);
	}

	for(int i = 1; i <= m1; i++){
		int u, v;
		u = originalF[i].first;
		v = originalF[i].second;
		if(setNum[u] != setNum[v]){
			res++;
		} else {
			adjListF[u].pb(v);
			adjListF[v].pb(u);		
		}
	}
	int currentSet2 = -1;
	for(int i = 1; i <= n; i++){
		if(setNumF[i] == -1) currentSet2++;
		dfs(i, setsF, setNumF, adjListF, currentSet2);
	}
	res += setsF.size() - sets.size();
	cout << res << ENDL;
	/*
	cout << "OBJSET" << endl;
	for(int i = 0; i < sets.size(); i++){
		for(auto num : sets[i]){
			cout << num << ' ';
		}
		cout << endl;
	}
	cout << "MYSET" << endl;
	for(int i = 0; i < setsF.size(); i++){
		for(auto num : setsF[i]){
			cout << num << ' ';
		}
		cout << endl;
	}
	*/
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