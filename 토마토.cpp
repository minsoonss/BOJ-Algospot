#include <stdio.h>
#include <queue>
using namespace std;

typedef struct position{
	int i;
	int j;
}position;
int zerocount;
int tomato[1000][1000];
int width, height;
queue<position> qu;
position xy;
int bfs();
int main(){
	scanf("%d %d",&width,&height);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			scanf("%d",&tomato[i][j]);
			if(tomato[i][j] == 1){
				xy.i = i;
				xy.j = j;
				qu.push(xy);
			}
			else if(tomato[i][j] == 0)zerocount++;
		}
	}
	if(qu.size() == 0){
		printf("-1");
		return 0;
	}
	else if(qu.size() == width*height){
		printf("0");
		return 0;
	}
	else{
		bfs();
	}
	return 0;	
}
int bfs(){
	position a;
	int max = -1;
	while(!qu.empty()){
		a = qu.front();
		qu.pop();
		if(tomato[a.i-1][a.j] == 0 && a.i-1 >= 0) {
			tomato[a.i-1][a.j] = tomato[a.i][a.j]+1;
			max = max > tomato[a.i-1][a.j] ? max : tomato[a.i-1][a.j];
			zerocount--;
			xy.i = a.i-1;
			xy.j = a.j;
			qu.push(xy);
		}
		if(tomato[a.i][a.j-1] == 0 && a.j-1 >= 0){
			tomato[a.i][a.j-1] = tomato[a.i][a.j]+1;
			max = max > tomato[a.i][a.j-1] ? max : tomato[a.i][a.j-1];
			zerocount--;
			xy.i = a.i;
			xy.j = a.j-1;
			qu.push(xy);
		}
		if(tomato[a.i][a.j+1] == 0 && a.j+1 < width){
			tomato[a.i][a.j+1] = tomato[a.i][a.j]+1;
			max = max > tomato[a.i][a.j+1] ? max : tomato[a.i][a.j+1];
			zerocount--;
			xy.i = a.i;
			xy.j = a.j+1;
			qu.push(xy);
		}
		if(tomato[a.i+1][a.j] == 0 && a.i+1 < height){
			tomato[a.i+1][a.j] = tomato[a.i][a.j]+1;
			max = max > tomato[a.i+1][a.j] ? max : tomato[a.i+1][a.j];
			zerocount--;
			xy.i = a.i+1;
			xy.j = a.j;
			qu.push(xy);
		}
	}
	if(zerocount != 0) printf("-1");
	else printf("%d",max-1);
	return 0;
}