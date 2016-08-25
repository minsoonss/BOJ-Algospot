#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];
int d[1001];
int num;
int main(){
	int sum = 0;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < num; i++){
		d[i] = 1;
		for(int j = 0; j <= i; j++){
			if(arr[i] < arr[j] && d[j]+1 > d[i]){
				d[i] = d[j]+1;
			}
		}
	}
	printf("%d\n",*max_element(d,d+num));

}