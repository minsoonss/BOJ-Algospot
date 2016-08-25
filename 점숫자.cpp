#include <cstdio>

typedef struct xy{
	int num;
	int x;
	int y;
}xy;
xy a[200][200];
void calc();
void init();
int main(){
	int testcase = 0;
	scanf("%d",&testcase);
	init();
	for(int i = 0; i < testcase; i++){
		calc();
	}
}
void init(){
	int count = 1;
	for(int j = 0; j < 200; j++){
		for(int i = 0; i < j+1; i++){
			a[j+i][j-i].num = count++;
			a[i+j][j-i].x = i+1;
			a[i+j][j-i].y = j+1;
		}
	}
}
void calc(){

}