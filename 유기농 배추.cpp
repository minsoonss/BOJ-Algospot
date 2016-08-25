#include <cstdio>
#include <queue>
using namespace std;

typedef struct position{
	int x;
	int y;
}position;

queue <position> q;
int arr[50][50];
void input(int n);
void calc(int m,int n);
int main(){
	int count;
	position p;
	int tc = 0;
	int M = 0;
	int N = 0;
	int	K = 0;
	scanf("%d",&tc);
	for(int i = 0; i < tc; i++){
		M = 0;
		N = 0;
		K = 0;
		count = 0;
		scanf("%d %d %d",&M, &N, &K);
		input(K);
		/*°è»ê*/
		for(int index1 = 0; index1 < M; index1++){
			for(int index2 = 0; index2 < N; index2++){
				if(arr[index1][index2] == 1){
					count++;
					arr[index1][index2]++;
					p.x = index1;
					p.y = index2;
					q.push(p);
					calc(M,N);
				}
			}
		}

		for(int index1 = 0; index1 < M; index1++){
			for(int index2 = 0; index2 < N; index2++){
				arr[index1][index2] = 0;
			}
		}
		printf("%d\n",count);
	}
}
void input(int n){
	int x = 0;
	int y = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		arr[x][y] = 1;
	}

}
void calc(int m,int n){
	position p;
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(arr[p.x+1][p.y] == 1 && p.x+1 < m){
			arr[p.x+1][p.y]++;
			p.x = p.x+1;
			q.push(p);
			p.x = p.x-1;
		}
		if(arr[p.x][p.y+1] == 1 && p.y+1 < n){
			arr[p.x][p.y+1]++;
			p.y = p.y+1;
			q.push(p);
			p.y = p.y-1;
		}
		if(arr[p.x-1][p.y] == 1 && p.x-1 >= 0){
			arr[p.x-1][p.y]++;
			p.x = p.x-1;
			q.push(p);
			p.x = p.x+1;
		}
		if(arr[p.x][p.y-1] == 1 && p.y-1 >= 0){
			arr[p.x][p.y-1]++;
			p.y = p.y-1;
			q.push(p);
			p.y = p.y+1;
		}
	}
}