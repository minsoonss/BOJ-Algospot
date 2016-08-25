#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int num;
	int p[10001] = {0,};
	scanf("%d",&num);
	for(int i = 1; i <= num; i++){
		scanf("%d",&p[i]);
	}
	int d[10001] = {0,};
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= i; j++){
			d[i] = max(d[i],d[i-j]+p[j]);
		}
	}
	printf("%d",d[num]);
}