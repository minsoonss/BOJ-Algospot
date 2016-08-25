#include <iostream>
using namespace std;

int d[51][2];
int p[50];
int cnt;
void dfs(int a){
	if(d[a][0] == -1 && d[a][1] == -1){
		cnt++;
		return;
	}
	if(d[a][0] != -1){
		dfs(d[a][0]);
	}
	if(d[a][1] != -1){
		dfs(d[a][1]);
	}
}
int main(){
	int n;
	int root;
	cin >> n;
	for(int i = 0; i < n; i++)d[i][0] = d[i][1] = p[i] = -1;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		if(temp == -1)root = i;
		if(temp != -1){
			p[i] = temp;
			if(d[temp][0] == -1){
				d[temp][0] = i;
			}else d[temp][1] = i;
		}
	}
	int temp;
	int t;
	cin >> temp;
	t = p[temp];
	if(d[t][0] == temp)d[t][0] = -1;
	else if(d[t][1] == temp)d[t][1] = -1;
	d[temp][0] = d[temp][1] = -1;
	if(temp != root)dfs(root);
	cout << cnt;
}