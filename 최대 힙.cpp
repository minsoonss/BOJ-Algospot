#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

priority_queue <int> q;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		if(x == 0){
			if(!q.empty()){
				printf("%d\n",q.top());
				q.pop();
			}
			else{
				printf("0\n");
			}
		}
		else q.push(x);
	}
}
