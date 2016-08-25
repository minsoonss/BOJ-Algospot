#include <cstdio>
#include <algorithm>
using namespace std;

int podo[10001];
int d[3][10001];
int num;
int main(){
	scanf("%d",&num);
	for(int i = 1; i <= num; i++){
		scanf("%d",&podo[i]);
	}
	for(int i = 1; i <= num; i++){
		d[0][i] = max(d[0][i-1],max(d[1][i-1],d[2][i-1]));
		d[1][i] = podo[i]+d[0][i-1];
		d[2][i] = podo[i]+d[1][i-1];
	}
	printf("%d",max(d[0][num],max(d[1][num],d[2][num])));
}