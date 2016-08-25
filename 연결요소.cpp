#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> a[1001];
bool check[1001];
void dfs(int start);
int cnt;
int main(){
	int n,e;
	scanf("%d %d",&n,&e);
	for(int i = 0; i < e; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		sort(a[i].begin(),a[i].end());
	}
	for(int i = 1; i <= n; i++){
		if(check[i] == false){
			cnt++;
			dfs(i);
		}
	}
	printf("%d",cnt);
}
void dfs(int start){
	check[start] = true;
	for(int i = 0; i < a[start].size(); i++){
		if(check[a[start][i]] == false){
			dfs(a[start][i]);
		}
	}
}