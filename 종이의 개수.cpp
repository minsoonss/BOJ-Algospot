#include <cstdio>

int num;
int count[3];
int arr[3000][3000];
void calc(int x, int y, int num);
int main(){
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	calc(0,0,num);
	for(int i = 0; i < 3; i++){
		printf("%d\n",count[i]);
	}
}
void calc(int x, int y, int num){
	int bcnt = 0;
	if(num == 1){
		count[arr[x][y]+1]++;
		return;
	}
	int temp = arr[x][y];
	for(int i = x; i < x+num; i++){
		for(int j = y; j < y+num; j++){
			if(temp != arr[i][j]){
				bcnt = 1;
				calc(x,y,num/3);
				calc(x+num/3,y,num/3);
				calc(x+2*num/3,y,num/3);
				calc(x,y+num/3,num/3);
				calc(x,y+2*num/3,num/3);
				calc(x+num/3,y+num/3,num/3);
				calc(x+num/3,y+2*num/3,num/3);
				calc(x+2*num/3,y+num/3,num/3);
				calc(x+2*num/3,y+2*num/3,num/3);
				break;
			}
		}
		if(bcnt == 1)break;
	}
	if(bcnt == 0)count[temp+1]++;

}