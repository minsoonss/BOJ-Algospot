#include <cstdio>

int main(){
	int testcase = 0;
	int num;
	int arr[41] = {0,1,};
	scanf("%d",&testcase);
	for(int i = 2; i <= 40; i++){
		arr[i] = arr[i-1]+arr[i-2];
	}
	for(int i = 0; i < testcase; i++){
		scanf("%d",&num);
		if(num == 0) printf("1 0\n");
		else printf("%d %d\n",arr[num-1],arr[num]);
	}
	return 0;
}
