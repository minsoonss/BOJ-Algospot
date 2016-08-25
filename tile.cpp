#include <stdio.h>

int num1, num2;
void input();
void calc();
int main(){
	int inputnum = 0;
	scanf("%d",&inputnum);
	for(int i = 0; i < inputnum; i++){
		input();
	}
}
void input(){
	scanf("%d %d",num1,num2);
	calc();
}
void calc(){
	int subnum1;
	int subnum2;
	int multinum;
	multinum = num1*num2;

	if(multinum%(num1*num2) != 0){
		if(num1
	}
	multinum = multinum/6; // 첫번째출력
}
