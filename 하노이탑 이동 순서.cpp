#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int cnt;
void hanoi(int n,int x,int y);
int main(){
	int input;
	scanf("%d",&input);
	cnt = pow(2,input)-1;
	printf("%d\n",cnt);
	hanoi(input,1,3);
}
void hanoi(int n,int x,int y){
	if(n == 0)return;
	hanoi(n-1,x,6-x-y);
	printf("%d %d\n",x,y);
	hanoi(n-1,6-x-y,y);
}