#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > graph;
vector < int > notebook;
vector < bool > check;
bool dfs(int here){
	for(int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if(check[there])continue;
		check[there] = true;
		if(notebook[there] == -1 || dfs(notebook[there])){
			notebook[there] = here;
			return true;
		}
	}
	return false;
}
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	graph.assign(n+1, vector <int>());
	notebook.assign(m+1, -1);
	for(int i = 1; i <= m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		check.assign(m+1,false);
		if(dfs(i))ans++;
	}
	printf("%d",ans);
}