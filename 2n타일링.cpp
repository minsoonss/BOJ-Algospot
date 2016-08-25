#include <cstdio>

int main(){
	int a = 0;
	int d[1001] = {0,};
	d[1] = 1;
	d[2] = 2;
	for(int i = 3; i <= 1000; i++){
		d[i] = (d[i-1]%10007+d[i-2]%10007)%10007;
	}
	scanf("%d",&a);
	printf("%d",d[a]);
}