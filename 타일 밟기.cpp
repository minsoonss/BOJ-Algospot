#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool flag[1000001];
int ori[3000];
int sum[3000];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		ori[i] = temp;
		flag[temp] = true;
	}//ют╥б
	for(int i = 0; i < n; i++){
		int cnt = 0;
		int j = 0;
		int start = ori[0];
		int idx = ori[i];
		int fsum = 0;
		int s = 0;
		for(;;start+=idx){
			if(flag[start]){
				cnt++;
				s += start;
			}
			else{
				if(cnt > 2 && fsum < s){
					fsum = s;
				}
				cnt = 0;
				s = 0;
				start = ori[++j]-idx;
				if(start+idx > ori[n-1])break;
			}
		}
		sum[i] = fsum;
		cout << sum[i] << '\n';
	}
	
}