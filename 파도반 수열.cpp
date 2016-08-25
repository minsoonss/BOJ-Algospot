#include <iostream>
using namespace std;

long long d[101];
int main(){
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	for(int i = 6; i < 101; i++)d[i] = d[i-1]+d[i-5];
	int t;
	int n;
	cin >> t;
	while(t--){cin >> n; cout << d[n] <<'\n';}
}