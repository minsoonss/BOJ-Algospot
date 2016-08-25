#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct Edge {
	int to, cost;
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};
const int inf = 1000000000;
int n;
vector<Edge> a[1001];
int dist[1001];
bool check[1001];
bool ans[1001];
void dijkstra(int start) {
	for (int i=1; i<=n; i++) {
		dist[i] = inf;
		check[i] = false;
	}
	dist[start] = 0;
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		pair<int,int> p = q.top();
		q.pop();
		int x = p.second;
		if (check[x]) {
			continue;
		}
		check[x] = true;
		for (int i=0; i<a[x].size(); i++) {
			int y = a[x][i].to;
			if (dist[y] > dist[x] + a[x][i].cost) {
				dist[y] = dist[x] + a[x][i].cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (start == i) continue;
		for (int j=0; j<a[i].size(); j++) {
			int from = i;
			Edge e = a[i][j];
			if (dist[from] + e.cost == dist[e.to]) {
				ans[from] = false;
			}
		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	for (int tc=1; tc<=t; tc++) {
		int m;
		scanf("%d %d",&n,&m);
		for (int i=1; i<=n; i++) {
			a[i].clear();
			ans[i] = true;
		}
		while (m--) {
			int from, to, cost;
			scanf("%d %d %d",&from, &to, &cost);
			a[from].push_back(Edge(to, cost));
			a[to].push_back(Edge(from, cost));
		}
		for (int i=1; i<=n; i++) {
			dijkstra(i);
		}
		printf("Case #%d\n",tc);
		int cnt = 0;
		for (int i=1; i<=n; i++) {
			if (ans[i]) {
				cnt += 1;
			}
		}
		printf("%d",cnt);
		for (int i=1; i<=n; i++) {
			if (ans[i]) {
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}