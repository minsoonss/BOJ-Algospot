#include <stdio.h>

int arr[100];
int brr[100];
int num1, num2;
void input();
void init();
void calc(int a);
int main(){
	int testNum = 0;
	scanf("%d",&testNum);
	for(int i = 0; i < testNum; i++){
		input();
		calc(i+1);
	}
}
void init(){
	for(int i = 0; i < sizeof(arr); i++){
		arr[i] = -1;
		brr[i] = -1;
	}
}
void input(){
	scanf("%d %d",&num1,&num2);
}
void calc(int a){
	int i = 0;
	int j = 0;
	int max = 0;
	int count = 0;
	while(1){
		arr[i] = num1%2;
		if(num1 == 0)break;
		else num1 = num1/2;
		i++;
	}
	while(1){
		brr[j] = num2%2;
		if(num2 == 0)break;
		else num2 = num2/2;
		j++;
	}
	max = i >= j ? i : j;
	for(int index = 0; index < max; index++){
		if(arr[index] != brr[index]){
			count++;
		}
	}
	printf("#testcase%d.\n%d\n",a,count);
}
