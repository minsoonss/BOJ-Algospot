#include <cstdio>
#include <algorithm>
using namespace std;
int p[501];
int d[501][501];
int s[501];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%d",&p[i]);
			d[i][i] = p[i];
			s[i] = p[i] + s[i-1];
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; i+j <= n; j++){
				d[j][j+i] = 2e9;
				int sum = s[j+i]-s[j-1];
				for(int k = j; k < i+j; k++){
					d[j][j+i] = min(d[j][j+i],sum+d[j][k]+d[k+1][i+j]);
				}
			}
		}
		printf("%d\n",d[1][n]-s[n]);
	}
}