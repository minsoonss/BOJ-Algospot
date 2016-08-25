#include <stdio.h>

int candy[10];
int subcandy[10];
int stdno;
void input();
int calc();
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		input();
		printf("%d\n",calc());
	}
}
void input(){
	scanf("%d",&stdno);
	for(int i = 0; i < stdno; i++){
		scanf("%d",&candy[i]);
	}
}
int calc(){
	int count = 0;
	while(1){
		int candycount = 0;
		for(int i = 0; i < stdno; i++){
			if(candy[i]%2 != 0){
				candy[i] = candy[i]+1;
			}
		}
		for(int i = 0; i < stdno; i++){
			if(candy[0] == candy[i])candycount++;
			if(candycount == stdno)return count;
		}
		for(int j = 0; j < stdno; j++){
				subcandy[j] = candy[j] / 2;
			}
		for(int i = 0; i < stdno; i++){
			if(i == 0)candy[i] = subcandy[i]+subcandy[stdno-1];
			else candy[i] = subcandy[i-1] + subcandy[i];
		}
		count++;
	}
}