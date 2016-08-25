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
	for(int i = 1; i <= n; i++){ 
		check.assign(m+1,false);
		if(dfs(i))ans++;
	}
	printf("%d",ans);
}


//#include<iostream>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//#define SOURCE 0
//#define SINK N+M+1
//using namespace std;
//int N, M;
//int net[2002][2002];
//vector<int> parents(2002);
//bool visit[2002];
//void backPath(int n) {
//	while (n != 0) {
//		int child = n;
//		n = parents[n];
//		//1감소
//		net[n][child] --;
//		net[child][n] ++;
//	}
//}
//bool dfs(int start) {
//	if (start == SINK) return true;
//	for (int i = 0; i < N + M + 2;i++) {
//		if (net[start][i] <= 0 || visit[i]==true) continue;
//		//뺵경로 설정
//		parents[i] = start;
//
//		visit[i] = true;
//		if (dfs(i)) return true;
//	}
//	return false;
//}
//int main()
//{
//	cin >> N >> M;
//	memset(net, 0, sizeof(net));
//	memset(visit, 0, sizeof(visit));
//	int a, b;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> a;
//		for (int j = 0; j < a; j++) {
//			cin >> b;
//			net[i][N+b] = 1;
//		}
//	}
//	//SOURCE -> 직원
//	for (int i = 1; i <= N; i++) net[0][i] = 1;
//	//일 ->SYNC
//	for (int i = 1+N; i <= N+M; i++) net[i][SINK] = 1;
//	int result = 0;
//	while (dfs(0)) {
//		result++;
//		//빽엣지
//		backPath(SINK);
//		memset(visit, 0, sizeof(visit));
//	}
//	cout << result << endl;
//	return 0;
//}

//#include <cstdio>
//#include <algorithm>
//#include <queue>
//#define SOURCE 0
//#define SINK n+m+1
//using namespace std;
//int d[2002][2002];
//
//int cnt;
//int precnt;
//int main(){
//	int n, m;
//	scanf("%d %d",&n,&m);
//	for(int i = 1; i <= n; i++){
//		d[0][i] = 1;
//		d[n+i][SINK] = 1;
//		int temp;
//		scanf("%d",&temp);
//		for(int j = 0; j < temp; j++){
//			int tmp;
//			scanf("%d",&tmp);
//			d[i][n+tmp] = 1;
//		}
//	}
//	precnt = -1;
//	while(1){
//		bool chk[2002] = {false,};
//		int p[2002] = {0,};
//		int stop = 0;
//		if(precnt == cnt)break;
//		//for(int i = 1; i <= n; i++){
//		//	if(d[SOURCE][i] == 0){
//		//		stop++;
//		//	}
//		//}
//		//if(stop == n)break;
//		queue <int> q;
//		chk[SOURCE] = true;
//		q.push(SOURCE);
//		p[SOURCE] = -1;
//		while(!q.empty()){
//			int temp;
//			temp = q.front();
//			q.pop();
//			if(temp == SINK){
//				int par = temp;
//				for(;;){
//					if(p[par] == -1)break;
//					d[p[par]][par] = 0;
//					d[par][p[par]] = 1;
//					par = p[par];
//				}
//				cnt++;
//				break;
//			}
//			for(int i = 1; i <= n+m+1; i++){
//				if(d[temp][i] == 1 && !chk[i]){
//					p[i] = temp;
//					q.push(i);
//					chk[i] = true;
//				}
//			}
//		}
//		precnt++;
//	}
//	printf("%d",cnt);
//}