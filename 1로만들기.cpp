#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001];
int main(){
	int a1=0,a2=0,a3=0;
	int inputnum = 0;
	a[1] = 0;
	for(int i = 2; i <= 1000000; i++){
		a[i] = a[i-1]+1;
		if(i%3 == 0 && a[i] > a[i/3]+1)a[i] = a[i/3]+1;
		if(i%2 == 0 && a[i] > a[i/2]+1)a[i] = a[i/2]+1;
	}
	scanf("%d",&inputnum);
	printf("%d",a[inputnum]);
}