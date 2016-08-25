#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int color[102][102];
int n[101];
int main(){
	int num;
	cin >> num;
	for(int i = 1; i <= num; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for(int j = a; j < a+c; j++){
			for(int k = b; k < b+d; k++){
				color[j][k] = i;
			}
		}
	}
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			n[color[i][j]]++;
		}
	}
	for(int i = 1; i <= num; i++){
		cout << n[i] << '\n';
	}
}