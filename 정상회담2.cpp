#include <iostream>
#define mod 987654321
using namespace std;

long long d[10001];
int main(){
	int n;
	cin >> n;
	d[0] = 1;
	d[2] = 1;
	d[4] = 2;
	for(int i = 6; i <= n; i+=2){
		int k = i-2;
		for(int j = i-2; j >= 0; j-=2){
			d[i] += d[j]%mod*d[k-j]%mod;
			d[i] %= mod;
		}
	}
	cout << d[n];
}