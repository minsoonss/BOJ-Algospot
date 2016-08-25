#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int d[1001];
	d[0] = 0;
	d[1] = 1;
	d[2] = 3;
	int n;
	scanf("%d",&n);
	for(int i = 3; i <= n; i++){
		d[i] = (d[i-1]+2*d[i-2])%10007;
	}
	printf("%d",d[n]);
}