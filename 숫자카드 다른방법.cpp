#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[500000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr,arr+n);
    cin >> m;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
		cout << binary_search(arr,arr+n,temp) << ' ';
    }
}