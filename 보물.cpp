#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int arr[50];
	int brr[50];
	int num;
	int result = 0;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < num; i++){
		scanf("%d",&brr[i]);
	}
	sort(arr,arr+num);
	sort(brr,brr+num);
	for(int i = 0; i < num; i++){
		result += arr[i]*brr[num-1-i];
	}
	printf("%d\n",result);
	return 0;
}