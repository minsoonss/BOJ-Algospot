#include <cstdio>
#include <vector>
using namespace std;
int n, modnum,sum;
int arr[1000000];
int sumarr[1000000];
int cnt;
int main(){
	scanf("%d %d",&n,&modnum);
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
		sum+= arr[i];
		sumarr[i] = sum;
	}
}