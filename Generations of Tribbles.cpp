#include <iostream>
using namespace std;

long long d[68];
int main(){
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for(int i = 4; i < 68; i++){
		d[i] = d[i-1]+d[i-2]+d[i-3]+d[i-4];
	}
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}