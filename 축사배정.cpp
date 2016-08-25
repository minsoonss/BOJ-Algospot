#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector < vector <int> > graph;
vector <bool> check;
vector <int> st;
bool dfs(int here){
	for(int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if(check[there])continue;
		check[there] = true;
		if(st[there] == -1 || dfs(st[there])){
			st[there] = here;
			return true;
		}
	}
	return false;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	graph.assign(n+1, vector<int>());
	st.assign(m+1, -1);
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
		if(dfs(i)){
			ans++;
		}
	}
	printf("%d",ans);
}