#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[4001][4001];
int main(){
	string a;
	string b;
	cin >> a;
	cin >> b;
	a = ' '+a;
	b = ' '+b;
	int alen = a.size();
	int blen = b.size();
	for(int i = 1; i <= a.size(); i++){
		for(int j = 1; j <= b.size(); j++){
			if(a[i] == b[j]){
				d[i][j] = d[i-1][j-1]+1;
			}
			else{
				d[i][j] = max(d[i-1][j],d[i][j-1]);
			}
		}
	}
	cout << d[alen][blen]-1;
}