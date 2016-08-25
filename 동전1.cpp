#include <cstdio>

int d[10001];
int p[100];
int main(){
	int n, res;
	scanf("%d %d",&n,&res);
	for(int i = 0; i < n; i++){
		scanf("%d",&p[i]);
	}
	d[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = p[i]; j <= res; j++){
			d[j] = d[j] + d[j-p[i]];
		}
	}
	printf("%d",d[res]);
}