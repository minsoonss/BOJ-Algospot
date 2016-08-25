#include <iostream>
#define mod 1000000000;
using namespace std;

int d[101][10];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i < 10; i++){
		d[1][i] = 1;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			d[i][j] = 0;
			if(j-1 >= 0){
				d[i][j] = d[i-1][j-1]+d[i][j];
			}
			if(j+1 <= 9){
				d[i][j] = d[i-1][j+1]+d[i][j];
			}
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for(int i = 0; i < 10; i++){
		ans += d[n][i];
	}
	cout << ans % mod;
}