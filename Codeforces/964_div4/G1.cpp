// unsolved
#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int leftPointer = 2, rightPointer = 999;
		while(leftPointer < rightPointer - 1){
			int x = (rightPointer + leftPointer) / 2;
			cout << "? " << x << " " << x << endl;
			int output;
			cin >> output;
			if(output == x * x){
				leftPointer = x;
			} else {
				rightPointer = x;
			}
		}
		cout << "! " << leftPointer << endl;
	}
	return 0;
}
