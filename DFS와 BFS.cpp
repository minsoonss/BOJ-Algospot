#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <int> a[1001];
bool check[1001];
void dfs(int start);
void bfs(int start);
int main(){
	int n, m, start;
	scanf("%d %d %d",&n,&m,&start);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		sort(a[i].begin(),a[i].end());
	}
	dfs(start);
	printf("\n");
	bfs(start);
}
void dfs(int start){
	check[start] = true;
	printf("%d ",start);
	for(int i = 0; i < a[start].size(); i++){
		if(check[a[start][i]] != true){
			dfs(a[start][i]);
		}
	}
}
void bfs(int start){
	queue <int> q;
	memset(check,false,sizeof(check));
	check[start] = true;
	q.push(start);
	while(!q.empty()){
		int temp;
		temp = q.front();
		q.pop();
		printf("%d ",temp);
		for(int i = 0; i < a[temp].size(); i++){
			int next = a[temp][i];
			if(check[next] != true){
				check[next] = true;
				q.push(next);
			}
		}
	}
}