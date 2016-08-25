#include <cstdio>

int main(){
	int a = 0;
	scanf("%d",&a);
	for(int i = 0; i < a; i++){
		for(int j = a-1; j > 0; j--){
			printf(" ");
		}
		for(int j = 0; j < 2*i+1; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}