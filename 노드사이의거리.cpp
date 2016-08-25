#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct info{
	int n;
	int w;
}info;
vector <info> v[1001];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n-1; i++){
		int a,b,c;
		info temp;
		scanf("%d %d %d",&a,&b,&c);
		temp.n = b;
		temp.w = c;
		v[a].push_back(temp);
		temp.n = a;
		v[b].push_back(temp);
	}
	for(int i = 0; i < m; i++){
		queue <int> q;
		bool flag[1001] = {false,};
		int len[1001] = {0,};
		int s,t;
		scanf("%d %d",&s,&t);
		q.push(s);
		flag[s] = true;
		while(!q.empty()){
			int temp;
			temp = q.front();
			q.pop();
			if(temp == t){
				break;
			}
			for(int j = 0; j < v[temp].size(); j++){
				if(!flag[v[temp][j].n]){
					q.push(v[temp][j].n);
					len[v[temp][j].n] = len[temp]+v[temp][j].w;
					flag[v[temp][j].n] = true;
				}
				
			}
		}
		printf("%d\n",len[t]);
	}

}