// unsolved
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void setIO(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

bool compare(const pair<int, int> &a, const pair<int,int> &b){
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO();
	int t; 
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<pair<int, int> >values(n + 1, pair<int,int>());
		for(int i = 1; i <= n; i++){
			cin >> values[i].first;
		}
		for(int i = 1; i <= n; i++){
			cin >> values[i].second; 
		}
		sort(values.begin(), values.end(), compare);
		for(int i = 1; i <= n; i++){
			cout << values[i].first << ' ' << values[i].second << endl;
		}
		int medianIndex = n / 2;
		int maxNumberIndex = n;

		cout << endl;
	}
	return 0;
}