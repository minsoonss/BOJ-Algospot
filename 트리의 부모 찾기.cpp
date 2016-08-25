#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[100001];
bool check[100001];
int p[100001];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue <int> q;
	q.push(1);
	check[1] = true;
	p[1] = 0;
	while(!q.empty()){
		int temp;
		temp = q.front();
		q.pop();
		for(int i = 0; i < v[temp].size(); i++){
			if(!check[v[temp][i]]){
				p[v[temp][i]] = temp;
				check[v[temp][i]] = true;
				q.push(v[temp][i]);
			}
		}
	}
	for(int i = 2; i <= n; i++){
		printf("%d\n",p[i]);
	}
}