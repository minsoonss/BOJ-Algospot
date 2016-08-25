#include <iostream>
#include <string>
#include <vector>
#define mod 1000000
using namespace std;

int d[5001];
int main(){
	string a;
	cin >> a;
	int len = a.size();
	a = " "+a;
	d[0] = 1;
	for(int i = 1; i <= len; i++){
		int value = a[i]-'0';
		if(0<value && value < 10){
			d[i] += d[i-1];
			d[i] %= mod;
		}
		if(i != 1 && a[i-1] != '0'){
			value = (a[i-1]-'0')*10 + a[i]-'0';
			if(9<value && value < 27){
				d[i] += d[i-2];
				d[i] %= mod;
			}
		}
	}
	cout << d[len];

}