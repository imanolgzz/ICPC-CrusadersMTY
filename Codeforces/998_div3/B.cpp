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
	int n, m;
	cin >> n >> m;
	vector< pair<vector<int>,int> > cowCards(n, pair<vector<int>,int>(vector<int>(m), 0));
	for(int i = 0; i < n; i++){
		cowCards[i].second = i+1;
		for(int j = 0; j < m; j++){
			cin >> cowCards[i].first[j];	
		}
		sort(cowCards[i].first.begin(), cowCards[i].first.end());
	}
	sort(cowCards.begin(), cowCards.end());
	int previous = -1;
	bool flag = true;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(cowCards[i].first[j] > previous){
				previous = cowCards[i].first[j];
			} else {
				flag = false;
				goto end;
			}	
		}
	}
end:
	if(flag){
		for(int i = 0; i < n; i++){
			cout << cowCards[i].second << ' ';
		}
		cout << ENDL;
	} else {
		cout << -1 << endl;
	}
	
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