#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
	int n;
	int w;
}info;
vector <info> v[10001];
queue <info> q;
int a[10001];
int b[10001];
bool acheck[10001];
bool bcheck[10001];
int main(){
	int n;
	int rmax;
	int lmax;
	info temp;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x,y,z;
		cin >> x >> y >> z;
		temp.n = y;
		temp.w = z;
		v[x].push_back(temp);
		temp.n = x;
		v[y].push_back(temp);
	}
	temp.n = 1;
	temp.w = 0;
	acheck[1] = true;
	a[1] = 0;
	q.push(temp);
	info cur;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(int i = 0; i < v[temp.n].size(); i++){
			if(!acheck[v[temp.n][i].n]){
				acheck[v[temp.n][i].n] = true;
				cur.n = v[temp.n][i].n;
				cur.w = a[temp.n]+v[temp.n][i].w;
				a[v[temp.n][i].n] = cur.w;
				q.push(cur);
			}
		}
	}
	rmax = *max_element(a,a+n+1);
	int maxidx = distance(a,max_element(a,a+n+1));
	temp.n = maxidx;
	temp.w = 0;
	bcheck[maxidx] = true;
	b[maxidx] = 0;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(int i = 0; i < v[temp.n].size(); i++){
			if(!bcheck[v[temp.n][i].n]){
				bcheck[v[temp.n][i].n] = true;
				cur.n = v[temp.n][i].n;
				cur.w = b[temp.n]+v[temp.n][i].w;
				b[v[temp.n][i].n] = cur.w;
				q.push(cur);
			}
		}
	}
	lmax = *max_element(b,b+n+1);
	cout << lmax;
}