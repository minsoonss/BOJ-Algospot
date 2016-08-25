#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2e9
using namespace std;

int M,N,L,G;
int h[101][101];
int v[101][101];
int D[101][101][2][202];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cin >> M >> N >> L >> G;
		for(int i = 1; i <= M; i++)for(int j = 1; j <= N-1; j++)cin >> h[i][j];
		for(int i = 1; i <= M-1; i++)for(int j = 1; j <= N; j++)cin >> v[i][j];
		for(int i = 1; i <= M; i++)for(int j = 1; j <= N; j++)for(int k = 0; k < 2; k++)for(int l = 0; l < 201; l++)D[i][j][k][l] = G+1;
		D[1][1][0][0] = D[1][1][1][0] = 0;
		int ans = INF;
		for(int i = 1; i <= M; i++)for(int j = 1; j <= N; j++)for(int l = 0; l < 201; l++)for(int k = 0; k < 2; k++)if(D[i][j][k][l] < G+1){
			if(i == M && j == N){
				if(ans > l)ans = l;
			}
			if (l < 200 && D[i][j][!k][l+1] > D[i][j][k][l])
                D[i][j][!k][l+1] = D[i][j][k][l];
            if (k){
                if (j < N && D[i][j+1][k][l] > D[i][j][k][l]+h[i][j])
                    D[i][j+1][k][l] = D[i][j][k][l]+h[i][j];
            }
            else{
                if (i < M && D[i+1][j][k][l] > D[i][j][k][l]+v[i][j])
                    D[i+1][j][k][l] = D[i][j][k][l]+v[i][j];
            }
		}
		if (ans < 2e9) printf("%d\n", (N+M-2)*L+ans);
        else puts("-1");
	}
}