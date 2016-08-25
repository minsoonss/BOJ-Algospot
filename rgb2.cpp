#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int d[3][1000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j= 0; j < 3; j++){
			cin >> d[j][i];
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			d[j][i] = d[j][i] + min(d[(j+1)%3][i-1],d[(j+2)%3][i-1]);
		}
	}
	int mini = d[0][n-1];
	for(int i = 0; i < 3; i++){
		if(mini > d[i][n-1])mini = d[i][n-1];
	}
	cout << mini;
}