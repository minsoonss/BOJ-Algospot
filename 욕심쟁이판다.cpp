#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	int x, y;
	int value;
}info;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int d[500][500];
int cnt[500][500];
info a[250000];
bool compare(const info& a, const info& b){
	if(a.value > b.value)return true;
	return false;
}
int main(){
	int n;
	cin >> n;
	int idx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> d[i][j];
			a[idx].x = i;
			a[idx].y = j;
			a[idx].value = d[i][j];
			idx++;
		}
	}
	sort(a,a+n*n,compare);
	int m = 0;
	for(int i = 0; i < n*n; i++){
		for(int j = 0; j < 4; j++){
			int tempx = a[i].x+dx[j];
			int tempy = a[i].y+dy[j];
			if(0 <= tempx && tempx < n && 0 <= tempy && tempy < n){
				if(d[tempx][tempy] < a[i].value){
					if(cnt[tempx][tempy] < cnt[a[i].x][a[i].y]+1){
						cnt[tempx][tempy] = cnt[a[i].x][a[i].y]+1;
						if(m < cnt[tempx][tempy])m = cnt[tempx][tempy];
					}
				}
			}
		}
	}
	cout << m+1;
}