#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
	int h;
	int n;
}info;
vector <int> v[101];
bool flag[101];
bool check;
int main(){
	int t;
	cin >> t;
	int s,g;
	cin >> s >> g;
	int n;
	cin >> n;
	int x,y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue <info> q;
	info temp;
	info in;
	flag[s] = true;
	temp.h = s;
	temp.n = 0;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp.h == g){
			check = true;
			break;
		}
		for(int i = 0; i < v[temp.h].size(); i++){
			if(!flag[v[temp.h][i]]){
				flag[v[temp.h][i]] = true;
				in.h = v[temp.h][i];
				in.n = temp.n+1;
				q.push(in);
			}
		}
	}
	if(check)cout << temp.n;
	else cout << -1;
}