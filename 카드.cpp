#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int t;
	long long temp;
	scanf("%d",&t);
	map <long long,int> m;
	for(int i = 0; i < t; i++){
		scanf("%lld",&temp);
		m[temp]++;
	}
	int d = 0;
	long long ans = 0;
	for(auto &p : m){
		if(p.second > d){
			d = p.second;
			ans = p.first;
		}else if(p.second == d){
			if(p.first < ans){
				ans = p.first;
			}
		}
	}
	printf("%lld",ans);
}