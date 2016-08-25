#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[10000000];
int main(){
	int a,p;
	int cnt = 1;
	int modnum = 0;
	int temp = 1;
	int sum = 0;
	scanf("%d %d",&a,&p);
	while(1){
		arr[a] = cnt++;
		while(1){
			modnum = a%10;
			a = a/10;
			for(int i = 0; i < p; i++){
				temp *= modnum;	
			}
			sum+=temp;
			if(a == 0){
				temp = 1;
				a = sum;
				break;
			}
			temp = 1;
		}
		if(arr[sum] !=0){
			printf("%d",arr[sum]-1);
			return 0;
		}
		sum = 0;
	}
}