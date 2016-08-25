#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector < vector < int > > v;
vector < vector < int > > r;
vector < int > cost, st, res;
vector < bool > check;
void dfsv(int num){
	check[num] = true;
	for(int i = 0; i < v[num].size(); i++){
		if(!check[v[num][i]])
			dfsv(v[num][i]);
	}
	st.push_back(num);
}
void dfsr(int num){
	check[num] = true;
	res.push_back(cost[num]);
	for(int i = 0; i < r[num].size(); i++){
		if(!check[r[num][i]])
			dfsr(r[num][i]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	v.assign(n+1,vector < int >());
	r.assign(n+1,vector < int >());
	cost.resize(n+1);
	for(int i = 1; i <= n; i++){
		int tmp;
		scanf("%d",&tmp);
		cost[i] = tmp;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int tmp;
			scanf("%1d",&tmp);
			if(tmp == 1){
				v[i].push_back(j);
				r[j].push_back(i);
			}
		}
	}
	check.assign(n+1,false);
	for(int i = 1; i <= n; i++){
		if(!check[i])
			dfsv(i);
	}
	check.assign(n+1,false);
	int ans = 0;
	for(int i = st.size()-1; i >= 0; i--){
		if(!check[st[i]]){
			dfsr(st[i]);
			sort(res.begin(),res.end());
			ans += res[0];
			res.clear();
		}
	}
	printf("%d",ans);
}