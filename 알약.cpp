#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long d[31][31];
int main(){
	for(int w = 0; w < 31; w++)d[0][w] = 1;
	for(int w = 1; w < 31; w++){
		for(int h = 0; h < 31; h++){
			if(h == 0)d[w][h] = d[w-1][h+1];
			else{
				d[w][h] = d[w-1][h+1]+d[w][h-1];		
			}
		}
	}
	while(1){
		int n;
		cin >> n;
		if(n == 0)break;
		cout << d[n][0] << '\n';
	}
}