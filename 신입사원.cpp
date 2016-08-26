#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int cnt = 0;
		int n;
		cin >> n;
		vector < pii > v(n);
		for(int j = 0; j < n; j++){
			int first,second;
			cin >> first >> second;
			v[j].first = first;
			v[j].second = second;
		}
		sort(v.begin(),v.end());
		pii temp;
		temp = v[0];
		for(int j = 1; j < n; j++){
			if(temp.second > v[j].second){
				cnt++;
				temp = v[j];
			}
		}
		cout << ++cnt << '\n';
	}
}