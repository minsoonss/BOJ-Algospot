#include <cstdio>

int m,n,x,y;
int calc();
int main(){
	int testcase = 0;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		scanf("%d %d %d %d",&m,&n,&x,&y);
		printf("%d\n",calc());
	}

}
int calc(){
	int nowX = 1;
	int nowY = 1;
	for(int i = 1;;i++){
		if(nowX == x && nowY == y)return i;
		else{
			if(/*안되는조건*/nowX == m && nowY == n && x != m && y != n)return -1;
			else{
				if(nowX%m == 0)	nowX = 1;
				else nowX++;
				if(nowY%n == 0) nowY = 1;
				else nowY++;
			}

		}
	}
}