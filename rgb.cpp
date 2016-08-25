#include <stdio.h>
#define max 1000

int house[max][3];
void calc(int a);
void input(int a);
int main(){
	int inputnum;
	scanf("%d",&inputnum);
	input(inputnum);
	calc(inputnum);
}
void input(int a){
	for(int i = 0; i < a; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d",&house[i][j]);
		}
	}
}
void calc(int a){
	int save[3] = {0,};
	int result;
	for(int i = 0; i < a-1; i++){
		for(int j = 0; j < 3; j++){
			if(save[(j+1)%3] == 0) {
				save[(j+1)%3] = house[i][j]+house[i+1][(j+1)%3];
			}
			else{
				save[(j+1)%3] = save[(j+1)%3] <= house[i][j]+house[i+1][(j+1)%3] ? save[(j+1)%3] : house[i][j]+house[i+1][(j+1)%3];
			}
			if(save[(j+2)%3] == 0) {
				save[(j+2)%3] = house[i][j]+house[i+1][(j+2)%3];
			}
			else{
				save[(j+2)%3] = save[(j+2)%3] <= house[i][j]+house[i+1][(j+2)%3] ? save[(j+2)%3] : house[i][j]+house[i+1][(j+2)%3];
			}
		}
		for(int j = 0; j < 3; j++){
			house[i+1][j] = save[j];
			save[j] = 0;
		}
	}result = house[a-1][0];
	for(int i = 0; i < 3; i++){
		
		if(house[a-1][i] < result)result = house[a-1][i];
	}
	printf("%d",result);
}