#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

bool bfs();
int main(){
	int t;
	bool check;
	scanf("%d",&t);
	while(t--){
		check = bfs();
		if(check == true)printf("YES\n");
		else printf("NO\n");
	}
}
bool bfs(){
	vector <int> a[20001];
	bool check[20001] = {false,};
	int n,e;
	int color[20001] = {0,};
	queue <int> q;
	scanf("%d %d",&n,&e);
	for(int i = 0; i < e; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	q.push(1);
	color[1] = 1;
	check[1] = true;
	while(!q.empty()){
		int node = q.front();
		int size = a[node].size();
		q.pop();
		for(int i = 0; i < size; i++){
			int next = a[node][i];
			if(check[next] == false){
				q.push(next);
				check[next] = true;
			}
			if(color[next] == 0){
				color[next] = 3-color[node];
			}
			else if(color[next] != 0 && color[next] != 3-color[node]){
				return false;
			}
		}
	}
	return true;
}