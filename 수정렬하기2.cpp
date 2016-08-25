#include <cstdio>
#include <algorithm>
using namespace std;

int a[10001];
int main(){
    int num = 0;
	int temp = 0;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d",&temp);
		a[temp]++;
	}
	for(int i = 1; i < 10001; i++){
		for(int j = 0; j < a[i]; j++){
			printf("%d\n",i);
		}
	}
}