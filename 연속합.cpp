#include <cstdio>
#include <algorithm>
using namespace std;

int d[1000001];
int p[1000001];
int main(){
	int num = 0;
	scanf("%d",&num);
	for(int i = 1; i <= num; i++){
		scanf("%d",&p[i]);
	}
	d[1] = p[1];
	for(int i = 2; i <= num; i++){
		d[i] = max(p[i],d[i-1]+p[i]);
	}
	printf("%d",*max_element(&d[1],&d[num+1]));
}