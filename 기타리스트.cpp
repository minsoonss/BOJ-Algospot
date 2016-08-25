#include <iostream>
#include <cmath>
using namespace std;

bool d[101][1001];
int p[100];
int main(){
	int n,s,m;
	cin >> n >> s >> m;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	d[0][s] = true;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j <= m; j++){
			if(cnt >= pow(2.0,i))break;
			if(d[i][j]){
				cnt++;
				if(j+p[i] <= m)d[i+1][j+p[i]] = true;
				if(j-p[i] >= 0)d[i+1][j-p[i]] = true;
			}
		}
	}
	for(int i = m; i >= 0; i++){
		if(d[n][i]){
			cout << i;
			return 0;
		}
	}
	cout << -1;
}