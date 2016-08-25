#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int p[100];
int d[100001];
int main(){
	int n, res;
	cin >> n >> res;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	sort(p,p+n);
	d[0] = 0;
	for(int i = 1; i <= res; i++)d[i] = 2e9;
	for(int i = 0; i < n; i++){
		for(int j = p[i]; j <= res; j++){
			d[j] = min(d[j], d[j-p[i]]+1);
		}
	}
	cout << d[res];
}