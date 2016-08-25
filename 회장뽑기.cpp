#include <cstdio>
#include <queue>
using namespace std;

queue <int> q;
int bf[50][50];

int nf[50][2];//친구점수저장&&플래그
void calc();
int main(){
	int num;//사람수
	int relation[2];
	int count = 1;
	scanf("%d",&num);
	while(true){
		scanf("%d %d",&relation[0],&relation[1]);
		if(relation[0] == -1 && relation[1] == -1){
			break;
		}
		else{
			bf[relation[0]-1][relation[1]-1] = 1;
			bf[relation[1]-1][relation[0]-1] = 1;
		}
	}
	for(int i = 0; i < num; i++){
		nf[1][i] = 1;
		for(int j = 0; j < num; j++){
			if(bf[i][j] == 1){
				q.push(j);
				nf[1][j] = 1;
			}
		}
		calc();
		for(int j = 0; j < num; j++){
			nf[1][j] = 0;
		}
	}
}
void calc(){
	int position = 0;
	while(true){
		position = q.front();
		q.pop();
		if(nf[1][position] != 1){
			
		}
	}
}