#include <cstdio>

int arr[100][100];
int input;
int che1;
void calc(int x, int y, int dis);
int main(){
	scanf("%d",&input);
	for(int i = 0; i < input; i++){
		for(int j = 0; j < input; j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	calc(0,0,input);
}
void calc(int x, int y, int dis){
	if(dis == 1){
		printf("%d",arr[x][y]);
		return;
	}
	che1 = 0;
	for(int i = x; i < x+dis; i++){
		for(int j = y; j < y+dis; j++){
			if(arr[x][y] != arr[i][j]){
				che1 = 1;
				break;
			}
		}
	}
	if(che1 == 1){
		printf("(");
		calc(x,y,dis/2);
		calc(x,y+dis/2,dis/2);
		calc(x+dis/2,y,dis/2);
		calc(x+dis/2,y+dis/2,dis/2);
		printf(")");
	}
	else{
		printf("%d",arr[x][y]);
	}
}