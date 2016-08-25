#include <cstdio>

int main(){
	int num = 0;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num-i-1; j++){
			printf(" ");
		}
		for(int j = 0; j < 2*i+1; j++){
			if(i == 0 || i == num-1){
				printf("*");
			}
			else{
				if(j == 0 || j == 2*i)printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}
}