#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	int x,y;
	int value;
}info;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
info u[250000];
int d[500][500];
int len[500][500];
bool compare(const info &a, const info &b){
	return a.value > b.value;
}
int main(){
	int n,m;
	int idx = 0;
	cin >> n >> m;
	int nm = n*m;
	for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
		cin >> d[i][j];
		idx = i*m+j;
		u[idx].x = i;
		u[idx].y = j;
		u[idx].value = d[i][j];
	}
	sort(u,u+nm,compare);
	len[0][0] = 1;
	for(int i = 1; i < nm; i++){
		for(int j = 0; j < 4; j++){
			int tempx = u[i].x+dx[j];
			int tempy = u[i].y+dy[j];
			if(0 <= tempx && tempx < n && 0 <= tempy && tempy < m){
				if(d[tempx][tempy] > d[u[i].x][u[i].y]){
					len[u[i].x][u[i].y] += len[tempx][tempy]; 
				}
			}
		}
		if(u[i].x == n-1 && u[i].y == m-1)break;
	}
	cout << len[n-1][m-1];
}