#include <iostream>
using namespace std;

int main(){
	int arr[301][301];
	int n,m,i,j,x,y;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		for(j =1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	int t;
	cin >> t;
	while(t--){
		int sum = 0;
		cin >> i >> j >> x >> y;
		for(int k = i; k <= x; k++){
			for(int l = j; l <= y; l++){
				sum += arr[k][l];
			}
		}
		cout << sum << '\n';
	}
}