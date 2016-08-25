#include <stdio.h>

int lotto[12];
int result[6];
int lottoNum;
void calc(int index1, int index2);
int main(){
	while(1){
		scanf("%d",&lottoNum);
		if(lottoNum == 0)break;
		else{
			for(int i = 0; i < lottoNum; i++){
				scanf("%d",&lotto[i]);
			}
			calc(0,0);
			printf("\n");
		}
	}
}
void calc(int index1, int index2){
	if(index1 == 5){
		result[index1] = lotto[index2];
		for(int i = 0; i < 6; i++){
			printf("%d ",result[i]);
		}printf("\n");
		if(index2 < lottoNum-1){
			calc(index1,index2+1);
		}
	}
	else{
		for(; index2 <= lottoNum - (6-index1); index2++){
			result[index1] = lotto[index2];
			if(index2 < lottoNum-1){
				calc(index1+1,index2+1);
			}
		}
	}
}