#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define INF 2e9
using namespace std;

struct Edge{
	int to, cost;
	Edge(int to,int cost): to(to), cost(cost){
	}
};
int v,e;
int start;
vector <Edge> a[20001];
priority_queue < pair <int,int>, vector<pair <int,int> >, greater<pair<int,int> > > q;
int dist[20001];
bool check[20001];
int main(){
	scanf("%d %d",&v,&e);
	scanf("%d",&start);
	for(int i = 0; i < e; i++){
		int n1,n2,n3;
		scanf("%d %d %d",&n1,&n2,&n3);
		a[n1].push_back(Edge(n2,n3));
	}
	q.push(make_pair(0,start));
	for(int i = 1; i <= v; i++){
		if(i != start)dist[i] = INF;
	}
	while(!q.empty()){ //first 거리 second 노드
		pair <int,int> p = q.top();
		q.pop();
		int x = p.second;
		if(check[x])continue;
		check[x] = true;
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i].to;
			if(dist[y] > dist[x] + a[x][i].cost){
				dist[y] = dist[x] + a[x][i].cost;
				q.push(make_pair(dist[y],y));
			}
		}
	}
	for(int i = 1; i <= v; i++){
		if(dist[i] == INF)printf("INF\n");
		else{
			printf("%d\n",dist[i]);
		}
	}
}