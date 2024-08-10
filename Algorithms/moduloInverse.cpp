#include <iostream>

using namespace std;

const int prime = 13;

int bruteForce(int a, int mod){
	// mod has to be a prime number to guarantee that there is a modular inverse
	int res = a;
	int output = 0;
	while((res * output) % mod != 1){
		output++;
	}
	return output;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << bruteForce(5, 13) << endl;

	return 0;
}
