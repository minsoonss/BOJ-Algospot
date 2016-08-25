#include <stdio.h>

void calc(int index);
int main(){
	int a;
	scanf("%d",&a);
	for(int i = 0; i < a; i++){
		calc(i);
	}
}
void calc(int index){
	int a;
	int sum = 0;
	scanf("%d",&a);
	for(int i = 1; i <= a+1; i++){
		sum += i;
	}
	printf("#testcase%d\n%d\n",index+1,sum);
}