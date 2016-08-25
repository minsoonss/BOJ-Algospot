#include <stdio.h>

int arr[1000];
void calc();
void init();
int main(){
	int inputnum;
	scanf("%d",&inputnum);
	for(int i = 0; i < inputnum; i++){
		init();
		calc();
	}
}
void init(){
	for(int i = 0; i < 1000; i++){
		arr[i] = -1;
	}
}
void calc(){
	int a = 0;
	int i = 0;
	scanf("%d",&a);
	a = a-1;
	while(1){
		if(a != 0){
			arr[i] = a%2;
			a = a/2;
			i++;
		}else break;
	}
	for(int j = i-1; j >= 0; j--){
		printf("%d",arr[j]);
	}
}