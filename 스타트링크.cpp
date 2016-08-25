#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];
bool flag[1000001];
queue <int> q;
int f,s,g,u,d;
int main(){
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	if(s==g){
		printf("0");
		return 0;
	}
	q.push(s);
	flag[s] = true;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if(temp == g){
			break;
		}
		if(temp+u <= f && !flag[temp+u]){
			q.push(temp+u);
			arr[temp+u] = arr[temp]+1;
			flag[temp+u] = true;
		}
		if(temp-d > 0 && !flag[temp-d]){
			q.push(temp-d);
			arr[temp-d] = arr[temp]+1;
			flag[temp-d] = true;
		}
	}
	if(flag[g])printf("%d",arr[g]);
	else printf("use the stairs");
}