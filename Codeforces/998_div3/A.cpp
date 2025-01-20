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
	int a1,a2,a4,a5;
	cin >> a1 >> a2 >> a4 >> a5;
	vector<int> nums = {a1, a2, 0, a4, a5};
	int maxN = 0, current = 0;
	nums[2] = nums[0] + nums[1];
	for(int i = 0; i < 3; i++){
		if(nums[i] + nums[i+1] == nums[i+2]) current++;
	}	
	maxN = max(current, maxN);
	current = 0;
	nums[2] = nums[3] - nums[1];	
	for(int i = 0; i < 3; i++){
		if(nums[i] + nums[i+1] == nums[i+2]) current++;
	}	
	maxN = max(current, maxN);
	current = 0;
	nums[2] = nums[4] - nums[3];	
	for(int i = 0; i < 3; i++){
		if(nums[i] + nums[i+1] == nums[i+2]) current++;
	}	
	maxN = max(current, maxN);
	cout << maxN << ENDL;
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