#include <cstdio>
#include <algorithm>
using namespace std;

int d[3][10001];
int p[10001];
int main(){
	int num;
	scanf("%d",&num);
	for(int i = 1; i <= num; i++){
		scanf("%d",&p[i]);
	}
	d[0][1] = 0;
	d[1][1] = p[1];
	d[2][1] = p[1];
	for(int i = 2; i <= num; i++){
		d[1][i] = max(d[1][i-2],d[2][i-2])+p[i];
		d[2][i] = d[1][i-1]+p[i];
	}
	printf("%d",max(d[1][num],d[2][num]));
}