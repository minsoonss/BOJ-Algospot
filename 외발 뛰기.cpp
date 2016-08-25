#include <cstdio>
#include <queue>
using namespace std;

typedef struct position{
	int x;
	int y;
}position;

queue <position> q;
bool check;
int arr[100][100];
int arraySize;
position p;
void input();
void calc(int a, int b);
int main(){
	int testcase = 0;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		for(int j = 0; j < arraySize; j++){
			for(int k = 0; k < arraySize; k++){
				arr[j][k] = 0;
			}
		}
		input();
		calc(0,0);
		if(check == true) printf("YES\n");
		else printf("NO\n");
		check = false;
	}
}
void input(){
	scanf("%d",&arraySize);
	for(int i = 0; i < arraySize; i++){
		for(int j = 0; j < arraySize; j++){
			scanf("%d",&arr[i][j]);	
		}
	}
}
void calc(int a, int b){
	if(arr[a][b]+a < arraySize){
		if(a == arraySize-1 && b == arraySize-1){
			check = true;
			return;
		}
		calc(arr[a][b]+a,b);
	}
	if(arr[a][b]+b < arraySize){
		if(a == arraySize-1 && b == arraySize-1){
			check = true;
			return;
		}
		calc(a,arr[a][b]+b);
	}
}