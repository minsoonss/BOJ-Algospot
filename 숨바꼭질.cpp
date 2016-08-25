#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int x,y;
queue <int> q;
int arr[200005];
bool flag[200005];
int main(){
	scanf("%d %d",&x,&y);
	flag[x] = true;
	q.push(x);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if(temp == y)break;
		if(!flag[temp+1] && temp+1 < 200004){
			q.push(temp+1);
			arr[temp+1] = arr[temp]+1;
			flag[temp+1] = true;
		}
		if(temp-1>-1 && !flag[temp-1]){
			q.push(temp-1);
			arr[temp-1] = arr[temp]+1;
			flag[temp-1] = true;
		}
		if(!flag[temp*2] && temp*2 < 200004){
			q.push(temp*2);
			arr[temp*2] = arr[temp]+1;
			flag[temp*2] = true;
		}
	}
	printf("%d",arr[y]);

}