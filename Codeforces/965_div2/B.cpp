#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void setIO(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// setIO();
	int t; 
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>numbers(n + 1);
		vector<int>prefixSum(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> numbers[i];
		}
		cout << numbers[n] << ' ';
		for(int i = 1; i < n; i++)
			cout << numbers[i] << ' ';


		cout << '\n';

	}
	return 0;
}