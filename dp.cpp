#include <stdio.h>

int arr[100][100];
void inputf();
void result(int num);
int main(){	
	int num;
	scanf("%d",&num);
	for(int i = 0; i < num; i++)inputf();
	return 0;
}
void inputf(){
	int num = 0;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		for(int j = 0; j < i+1; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	result(num);
}
void result(int num){
	int carry;
	for(int i = num-1; i > 0; i--){
		for(int j = num-1; j > 0; j--){
			carry = arr[i][j] >= arr[i][j-1] ? arr[i][j]:arr[i][j-1];
			arr[i-1][j-1] += carry;
		}
	}
	printf("%d\n",arr[0][0]);
}