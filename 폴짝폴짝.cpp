#include <stdio.h>
#include <queue>
using namespace std;

typedef struct state{
	int now;
	int step;
	int mod;//남은거리
}state;

int frog[10000];
queue <state> q;
int main(){
	int num;
	int distance;
	int start, finish;
	state input;
	state output;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d",&frog[i]);
	}
	scanf("%d %d",&start,&finish);
	start -= 1;
	finish -= 1;
	distance = finish - start;
	for(int i = 1; i <= distance; i++){
		if(frog[start]*i <= distance){
			input.now = frog[start]*i;
			input.step = 1;
			input.mod = distance - frog[start]*i;
			q.push(input);
			if(frog[start]*i == distance){
				printf("1");
				return 0;
			}
		}
		else{
			if(frog[start]*i > distance && q.empty()){
				printf("-1");
				return 0;
			}
			break;
		}
	}
	while(1){
		output = q.front();
		q.pop();
		for(int i = 1; i < output.mod; i++){
			if(frog[output.now]*i <= output.mod){
				input.now = frog[output.now]*i;
				input.step = output.step+1;
				input.mod = output.mod - frog[output.now]*i;
				q.push(input);
				if(frog[output.now]*i == output.mod){
					printf("%d",output.step+1);
					return 0;
				}
			}
			else
			{
				break;
			}
		}
		if(q.empty()){
			printf("-1");
			return 0;
		}
	}
}