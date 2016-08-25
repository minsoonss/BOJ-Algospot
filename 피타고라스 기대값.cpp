#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double team[1001][2] = {0,}; //득점 0 실점 1 경기수 2
		double res[1001] = {0,};
		int n,m;
		long long maxi,mini;
		maxi = 0;
		mini = INT_MAX;
		scanf("%d %d",&n,&m);
		for(int i = 0; i < m; i++){
			int a,b,p,q;
			scanf("%d %d %d %d",&a,&b,&p,&q);
			team[a][0] += p;
			team[b][0] += q;
			team[a][1] += q;
			team[b][1] += p;
		}
		for(int i = 1; i <= n; i++){
			double ans;
			if(team[i][0] == 0 && team[i][1] == 0)ans = 0;
			else{
				ans = (pow(team[i][0],2)/(pow(team[i][0],2)+pow(team[i][1],2)));
				ans *= 1000;
			}
			if(ans > maxi)maxi = ans;
			if(ans < mini)mini = ans;
		}
		printf("%lld\n%lld\n",maxi,mini);
	}
}