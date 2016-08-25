#include <iostream>
using namespace std;

int main(){
	int t;
	int pos = 1;
	cin >> t;
	int x,y;
	for(int i = 0; i < t; i++){
		cin >> x >> y;
		if(x == pos){
			pos = y;
		}else if(y == pos){
			pos = x;
		}
	}
	cout << pos;
}