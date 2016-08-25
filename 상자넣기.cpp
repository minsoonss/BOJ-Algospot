#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	int max = 0;
	cin >> t;
	vector <int> d(t);
	vector <int> box(t);
	for(int i = 0; i < t; i++){
		d[i] = 1;
		cin >> box[i];
	}
	for(int i = 1; i < t; i++){
		for(int j = 0; j < i; j++){
			if(box[i] > box[j] && d[i] < d[j]+1){
				d[i] = d[j]+1;
			}
		}
		if(max < d[i])max = d[i];
	}
	cout << max;
}