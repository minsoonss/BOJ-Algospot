#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][1001];
int main(){
	int n,m,i,j;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			cin >> d[i][j];
			if(i == 0 && j > 0)d[i][j] += d[i][j-1];
			else if(j == 0 && i > 0)d[i][j] += d[i-1][j];
			else{
				d[i][j]+=max(d[i-1][j-1],max(d[i-1][j],d[i][j-1]));          
			}
		}
	}
	cout << d[n][m];
}