#include <cstdio>
#include <iostream>
using namespace std;

int d[100001];
int main(){
	int n;
	int ans = 0;
	cin >> n;
	d[0] = 1;
	d[1] = 1;
	ans = 2;
	for(int i = 2; i <= n; i++){
		d[i] = (ans-d[i-1]+1+9901)%9901;
		ans += d[i]*2;
		ans %= 9901;
	}
	cout << (ans+1)%9901;
}