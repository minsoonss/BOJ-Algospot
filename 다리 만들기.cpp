#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int d[100][100];
int len[100][100];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			len[i][j] = -1;
			cin >> d[i][j];
			if(d[i][j] == 1)len[i][j] = 0;
		}
	}
}