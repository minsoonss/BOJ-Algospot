#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][31][3]; //�ð� �̵�Ƚ�� ����ġ
int p[1001];
int main(){
	int t, w;
	int cur = 1;
	cin >> t >> w;
	for(int i = 0; i < t; i++){
		cin >> p[i+1];
	}
	if(p[1] == 1)d[1][0][1] = 1;
	else d[1][1][2] = 1;
	for(int i = 1; i <= t; i++){//�ð���
		for(int j= 0; j <= i && j <= w; j++){//�̵�Ƚ��
			for(int k = 1; k < 3; k++){//��ġ
				//�ȿ����϶�
				if(k == p[i]){
					d[i][j][k] = max(d[i-1][j][k]+1,d[i][j][k]);
				}
				else{
					d[i][j][k] = max(d[i][j][k],d[i-1][j][k]);
				}
				//�����϶�
				if(j > 0){
					if(3-k == p[i]){
						d[i][j][k] = max(d[i][j][k],d[i-1][j-1][3-k]+1);
					}
					else{
						d[i][j][k] = max(d[i][j][k],d[i-1][j-1][3-k]);
					}
				}
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= w; i++){
		for(int k = 1; k < 3; k++){
			if(res < d[t][i][k]){
				res = d[t][i][k];
			}
		}
	}
	cout << res;
}