#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
	int x,y,o;
}info;
info d[100001];
bool compare1(const info& a, const info& b){
	if(a.x < b.x)
	{
		return true;
	}
	else if(a.x == b.x){
		if(a.y < b.y)return true;
		return false;
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> d[i].x >> d[i].y;
		}
		sort(d+1,d+n+1,compare1);
		int o = 1;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(d[i].x != d[j].x){
					
				}
			}
		}
	}
}