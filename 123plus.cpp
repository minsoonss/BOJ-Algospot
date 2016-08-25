#include <stdio.h>

int main(){
	int testcase = 0;
	int inputnum = 0;
	int plus[11] = {0,1,2,4};
	for(int i = 4; i < 11; i++){
		plus[i] = plus[i-2]+plus[i-1]+plus[i-3];
	}
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		scanf("%d",&inputnum);
		printf("%d\n",plus[inputnum]);
	}
}