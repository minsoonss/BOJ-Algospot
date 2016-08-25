#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector < vector <int> > graph;
vector < bool > check;
vector < int > work;
bool dfs(int here){
	for(int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	graph.assign(n+1,vector<int>());
	work.assign(m+1,-1);
	for(int i = 1; i <= n; i++){
		int tmp;
		scanf("%d",&tmp);
		for(int j = 0; j < tmp; j++){
			int tmp2;
			scanf("%d",&tmp2);
			graph[i].push_back(tmp2);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		check.assign(m+1,false);
		if(dfs(i))ans++;
	}
	int preans = ans;
	for(;;){
		for(int i = 1; i <= n && k > 0; i++){
			check.assign(m+1,false);
			if(dfs(i)){
				ans++;
				k--;
			}
		}
		if(k == 0 || preans == ans)break;
		preans = ans;
	}
	printf("%d",ans);
}