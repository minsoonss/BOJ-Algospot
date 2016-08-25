#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct shark{
	int size;
	int vel;
	int wiz;
	//shark(int size, int vel, int wiz) : size(size), vel(vel), wiz(wiz){}
}shark;

vector <shark> info;
vector < vector <int> > graph;
vector < bool > check;
vector < int > eat;
bool dfs(int here){
	for(int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if(check[there])continue;
		check[there] = true;
		if(eat[there] == -1 || dfs(eat[there])){
			eat[there] = here;
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	info.resize(n+1);
	graph.assign(n+1,vector <int>());
	eat.assign(n+1,-1);
	for(int i = 1; i <= n; i++){
		int size, vel, wiz;
		scanf("%d %d %d",&size,&vel,&wiz);
		shark temp;
		temp.size = size;
		temp.vel = vel;
		temp.wiz = wiz;
		info[i]=temp;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(info[i].size == info[j].size && info[i].vel == info[j].vel && info[i].wiz == info[j].wiz){
				if(i < j)graph[i].push_back(j);
			}else if(info[i].size >= info[j].size && info[i].vel >= info[j].vel && info[i].wiz >= info[j].wiz){
				graph[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for(int roof = 0; roof < 2; roof++){
		for(int i = 1; i <= n; i++){
			check.assign(n+1,false);
			if(dfs(i))ans++;
		}
	}
	printf("%d",n-ans);
}