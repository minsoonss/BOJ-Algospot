#include <cstdio>
#include <cstring>

int count;
bool check[1001] = {false,};
int num;
int a[1001];
void input();
void dfs(int start);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		count = 0;
		input();
		for(int i = 1; i <= num; i++){
			if(check[i] == false){
				check[i] = true;
				count++;
				dfs(i);
			}
		}
		printf("%d\n",count);
		memset(check,false,sizeof(check));
		memset(a,0,sizeof(a));
	}
}
void input(){
	scanf("%d",&num);
	for(int i = 1; i <= num; i++){
		scanf("%d",&a[i]);
	}
}
void dfs(int start){
	check[start] = true;
	if(check[a[start]] == true)return;
	else dfs(a[start]);
}