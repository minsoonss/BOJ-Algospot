#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int d[100001];
int main(){
	int n;
	for(int i = 1; i*i < 100001; i++){
		int temp = pow(i,2);
		for(int j = 1; j < 100001; j++){
			if(i == 1){
				d[j] = j;
			}
			else{
				/*if(j < temp)d[j] = d[j-1]+1;
				else */if(j >= temp && i > 1){
					d[j] = min(d[j],d[j-temp]+1);
				}
			}
		}
	}

	cin >> n;
	cout << d[n];
}