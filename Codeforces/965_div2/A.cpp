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
		int xc, yc, k;
		cin >> xc >> yc >> k;
		vector<int> xPoints, yPoints;
		if(k & 1){
			xPoints.push_back(xc);
			yPoints.push_back(yc);
			k--;
		}
		int xDistance = 1, yDistance = 1;
		while(k > 0){
			xPoints.push_back(xc + xDistance);
			xPoints.push_back(xc - xDistance);
			yPoints.push_back(yc + yDistance);
			yPoints.push_back(yc - yDistance);
			xDistance++;
			yDistance++;
			k = k - 2;
		}
		for(int i = 0; i < xPoints.size(); i++){
			cout << xPoints[i] << ' ' << yPoints[i] << '\n';
		}
	}
	return 0;
}
