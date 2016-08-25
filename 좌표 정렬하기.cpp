#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct pos{
	int x,y;
}pos;
bool compare(const pos &a, const pos &b){
	if(a.x < b.x)return true;
	else if(a.x == b.x){
		if(a.y < b.y)return true;
		else return false;
	}
	else return false;
}
int main(){
	int num;
	pos a[100000];
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a,a+num,compare);
	for(int i = 0; i < num; i++)printf("%d %d\n",a[i].x,a[i].y);
}