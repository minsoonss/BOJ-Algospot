#include <iostream>
#define mod 10007;
using namespace std;

int d[1001][10];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 10; i++)d[1][i] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			d[i][j] = 0;
			for(int k = 0; k <= j; k++){
				d[i][j] += d[i-1][k];
			}
			d[i][j] %= mod;
		}
	}
	int ans = 0;
	for(int i = 0; i < 10; i++)ans += d[n][i];
	cout << ans%mod;
}