#include <stdio.h>

int arr[31];
int input();
void calc(int count);
int main(){
	int inputnum;
	scanf("%d",&inputnum);
	int count = 0; //¹è¿­ÀÇ °¹¼ö
	for(int i = 0; i < inputnum; i++){
		count = input();
		calc(count);
	}
}
int input(){
	int j = 0;
	for(int i = 0; i < 31; i++){
		arr[i] = -1;
	}
	while(1){
		int enter;
		scanf("%d",&enter);
		if(enter != 0 && enter != 1)break;
		else{
			arr[j] = enter;
			j++;
		}
	}
	return j;
}
void calc(int count){

}