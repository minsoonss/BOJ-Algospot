#include <stdio.h>

char password[100];
int num;

void calc();
int main(){
	int inputnum;
	scanf("%d",&inputnum);
	for(int i = 0; i < inputnum; i++){
		scanf("%d %s",&num,password);
		calc();
	}
	return 0;
}
void calc(){
	for(int i = 0; i < num; i++){
		if(password[i] == password[i+1]){
			if(i == 0){
				
			}
		}
	}
}