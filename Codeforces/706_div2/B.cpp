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
	int n, k;
	cin >> n >> k;
	unordered_set<int> nums;
	vector<bool> present(1e6, false);
	int maxNum = 0;
	int res = 0;
	int mex = 0;
	int previous = -1;
	for(int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		nums.insert(tmp);
		maxNum = max(maxNum, tmp);
		if(tmp < 1e6){
			present[tmp] = true;
		}
	}
	for(int i = 0; i < 1e6; i++){
		if(!present[i]){
			mex = i;
			break;
		}
	}
	int flag = 0;
	while(k > 0){
		if(mex > maxNum){
			flag = 1;
			break;
		}
		int newNum = ceil((maxNum + mex)/(long double)(2));
		if(newNum == previous){
			break;
		}
		previous = newNum;
		nums.insert(newNum);
		if(newNum < 1e6){
			present[newNum] = true;
		}
		for(int i = mex; i < 1e6; i++){
			if(!present[i]){
				mex = i;
				break;
			}
		}
		k--;
	}
	if(flag == 0){
		cout << nums.size() << endl;	
	} else if(flag == 1){
		cout << nums.size() + k << endl;
	} else {
		cout << "Error" << endl;
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