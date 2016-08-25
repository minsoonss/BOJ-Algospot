#include <cstdio>
#include <vector>
using namespace std;

vector < vector <int> > graph;
vector < bool > check;
vector < int > work;
bool dfs(int here){
	for(int i = 0; i < graph[here].size(); i++){
		int there  = graph[here][i];
		if(check[there])continue;
		check[there] = true;
		if(work[there] == -1 || dfs(work[there])){
			work[there] = here;
			return true;
		}
	}
	return false;
}
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	graph.assign(n+1, vector <int>());
	work.assign(m+1,-1);
	for(int i = 1; i <= n; i++){
		int tmp;
		scanf("%d",&tmp);
		for(int j = 0; j < tmp; j++){
			int num;
			scanf("%d",&num);
			graph[i].push_back(num);
		}
	}
	int ans = 0;
	for(int roof = 0; roof < 2; roof++){
		for(int i = 1; i <= n; i++){
			check.assign(m+1,false);
			if(dfs(i))ans++;
		}
	}
	printf("%d",ans);
}