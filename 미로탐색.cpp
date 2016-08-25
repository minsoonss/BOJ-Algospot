#include <cstdio>

int arr[101][101];
int brr[101][101];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int min;
int sero,garo;
bool flag;
void dfs(int x,int y, int prex, int prey);
int main(){
	scanf("%d %d",&sero,&garo);
	for(int i = 0; i < sero; i++){
		for(int j = 0; j < garo; j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	brr[0][0] = 1;
	dfs(0,0,0,0);
	printf("%d",brr[sero-1][garo-1]);
}
void dfs(int x,int y, int prex, int prey){
	for(int i = 0; i < 4; i++){
		if(sero>x+dx[i] && x+dx[i]>=0 &&
			garo > y+dy[i] && y+dy[i] >= 0 &&
			arr[x+dx[i]][y+dy[i]] != 0 &&
			!(x+dx[i] == prex && y+dy[i] == prey))
		{
			if(brr[x+dx[i]][y+dy[i]] == 0 || brr[x][y]+1 < brr[x+dx[i]][y+dy[i]]){
				brr[x+dx[i]][y+dy[i]] = brr[x][y]+1;
				dfs(x+dx[i],y+dy[i],x,y);
			}
		}
	}

}