#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int V,E;
vector<vector<int> > v,G,scc;
vector<int> tmp,tmp1;
bool b[11111];
void go(int now) {
	b[now] = true;
	for ( int i = 0 ; i < v[now].size() ; i++ )
		if ( !b[v[now][i]] )
			go(v[now][i]);
	tmp.push_back(now);
}
void go1(int now) {
	b[now] = true;
	tmp1.push_back(now);
	for ( int i = 0 ; i < G[now].size() ; i++ )
		if ( !b[G[now][i]] )
			go1(G[now][i]);
}
int main() {
	scanf("%d%d",&V,&E);
	v.resize(V+1);
	G.resize(V+1);
	for ( int i = 0 ; i < E; i++ ) {
		int st,ed;
		scanf("%d%d",&st,&ed);
		v[st].push_back(ed);
		G[ed].push_back(st);
	}
	memset(b,false,sizeof(b));
	for ( int i = 1 ; i <= V ; i++ )
		if ( !b[i] )
			go(i);
	memset(b,false,sizeof(b));
	for ( int i = (int)tmp.size()-1 ; i >= 0 ; i-- ) {
		if ( !b[tmp[i]] ){
			go1(tmp[i]);
			sort(tmp1.begin(),tmp1.end());
			tmp1.push_back(-1);
			scc.push_back(tmp1);
			tmp1.clear();
		}
	}
	sort(scc.begin(),scc.end());
	printf("%d\n",(int)scc.size());
	for ( int i = 0 ; i < scc.size() ; i++ ) {
		for ( int j = 0 ; j < scc[i].size() ; j++ )
			printf("%d ",scc[i][j]);
		puts("");
	}
	return 0;
}