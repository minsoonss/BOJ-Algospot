#include <iostream>

int d[31];
int main(){
	int n;
	d[1] = 1;
	d[2] = 3;
	for(int i = 3; i < 31; i++){
		d[i] = d[i-2]*2+d[i-1];
	}
	std :: cin >> n;
	if(n%2 == 0){
		d[n] = d[n]-d[n/2];
	}else{
		d[n] = d[n]-d[n/2]+1;
	}
	std :: cout << d[n];
}